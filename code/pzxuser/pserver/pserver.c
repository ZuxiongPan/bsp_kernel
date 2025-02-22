#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <linux/netlink.h>
#include <user/user_log.h>
#include <ukcomm/comm_funcs.h>
#include <ukcomm/comm_netlink.h>
#include <ukcomm/netlink_msgid.h>

static void send_netlink_message(int sock, struct sockaddr_nl *dest, unsigned int id, \
	unsigned int dataLen, void *data);

int main()
{
	struct sockaddr_nl srcAddr, destAddr;
	char buffer[NLMSG_SPACE(NETLINK_MESSAGE_MAXLEN)];
	char data[MSG_PAYLOAD_MAXLEN];
	int group = NTELINK_PZXGROUP;
	
	int sockFd = socket(PF_NETLINK, SOCK_RAW, NETLINK_PZXPROTOCOL);
	if(sockFd < 0)
	{
		user_error("create netlink socket failed!");
		return -1;
	}
	
	memset(&srcAddr, 0, sizeof(struct sockaddr_nl));
	srcAddr.nl_family = AF_NETLINK;
	srcAddr.nl_pid = getpid();
	srcAddr.nl_groups = group;
	
	if(bind(sockFd, (struct sockaddr *)&srcAddr, sizeof(srcAddr)) < 0)
	{
		user_error("bind netlink socket failed!");
		close(sockFd);
		return -1;
	}

    // add into broadcast group explicitly
    if (setsockopt(sockFd, SOL_NETLINK, NETLINK_ADD_MEMBERSHIP, &group, sizeof(group)) < 0)
	{
        user_error("setsockopt(NETLINK_ADD_MEMBERSHIP) failed");
        close(sockFd);
        return -1;
    }	

    memset(&destAddr, 0, sizeof(struct sockaddr_nl));
    destAddr.nl_family = AF_NETLINK;
    destAddr.nl_pid = 0;   // 0 means kernel
    destAddr.nl_groups = 0;	// kernel groups is 0

	while(1)
	{
		ssize_t len = recv(sockFd, buffer, sizeof(buffer) - 1, 0);
		if(len < 0)
		{
			user_error("receive message from kernel failed!");
			continue;
		}
		
		struct nlmsghdr *nlh = (struct nlmsghdr *)buffer;
		struct pzx_netlink_msg *pkmsg = (struct pzx_netlink_msg *)NLMSG_DATA(nlh);
		if(PTR_INVALID(pkmsg))
		{
			user_info("receive invalid message.\n");
			continue;
		}
		snprintf(data, MSG_PAYLOAD_MAXLEN, "user receive message 0x%x.", pkmsg->msgId);
		send_netlink_message(sockFd, &destAddr, pkmsg->msgId, strlen(data) + 1, data);
		user_info("kernel message: \'%s\'\n", pkmsg->payloadLen ? pkmsg->payload : "nul");
	}
	
	close(sockFd);
	return 0;
}

static void send_netlink_message(int sock, struct sockaddr_nl *dest, unsigned int id, \
	unsigned int dataLen, void *data)
{
    struct iovec iov;
    struct msghdr msg;
	char buffer[NLMSG_SPACE(NETLINK_MESSAGE_MAXLEN)];
    struct nlmsghdr *nlh = (struct nlmsghdr *)buffer;
	unsigned int dataRealLen = dataLen > MSG_PAYLOAD_MAXLEN ? MSG_PAYLOAD_MAXLEN : dataLen;
	
    nlh->nlmsg_len = NLMSG_SPACE(NETLINK_MESSAGE_MAXLEN);
    nlh->nlmsg_pid = getpid();
    nlh->nlmsg_flags = 0;
	struct pzx_netlink_msg *pumsg = (struct pzx_netlink_msg *)NLMSG_DATA(nlh);
	pumsg->msgId = id;
	pumsg->payloadLen = dataRealLen;
	if(dataLen > 0)
		memcpy(pumsg->payload, data, dataRealLen);

    iov.iov_base = (void *)nlh;
    iov.iov_len = nlh->nlmsg_len;

    memset(&msg, 0, sizeof(struct msghdr));
    msg.msg_name = (void *)dest;
    msg.msg_namelen = sizeof(struct sockaddr_nl);
    msg.msg_iov = &iov;
    msg.msg_iovlen = 1;

    if (sendmsg(sock, &msg, 0) < 0)
        user_error("send message to kernel failed!");
	
	return ;
}