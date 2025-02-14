#include <sys/socket.h>
#include <sys/uio.h>
#include <stdio.h>
#include <linux/netlink.h>
#include <ukcomm/comm_netlink.h>
#include <user/user_netlink.h>

int send_user_msg(const struct netlink_uobj *puobj, enum msg_type msgType, unsigned int msgId)
{
	char buffer[NETLINK_MESSAGE_MAXLEN];
	struct msghdr msgHeader;
	struct iovec iov;
	struct nlmsghdr *nlHeader = (struct nlmsghdr*)buffer;
	struct pzx_netlink_msg *pumsg = (struct pzx_netlink_msg*)NLMSG_DATA(nlHeader);
	nlHeader->nlmsg_len = NETLINK_MESSAGE_MAXLEN;
	nlHeader->nlmsg_type = 0;
	nlHeader->nlmsg_flags = 0;
	nlHeader->nlmsg_pid = puobj->pid;
	pumsg->msgType = msgType;
	pumsg->msgId = msgId;
	pumsg->payloadLen = 0;
	
	iov.iov_base = (void*)nlHeader;
	iov.iov_len = nlHeader->nlmsg_len;
	msgHeader.msg_name = (void*)(&puobj->destAddr);
	msgHeader.msg_namelen = sizeof(puobj->destAddr);
	msgHeader.msg_iov = &iov;
	msgHeader.msg_iovlen = 1;
	
	if(sendmsg(puobj->sockFd, &msgHeader, 0) < 0)
	{
		perror("user: send netlink message failed!");
		return -1;
	}
	
	return 0;
}

int recv_kernel_msg(const struct netlink_uobj *puobj, struct msghdr *pMsgHeader, struct iovec *piov)
{	
    pMsgHeader->msg_name = (void*)(&puobj->srcAddr);
    pMsgHeader->msg_namelen = sizeof(puobj->srcAddr);
    pMsgHeader->msg_iov = piov;
    pMsgHeader->msg_iovlen = 1;
	
	return recvmsg(puobj->sockFd, pMsgHeader, 0);
}