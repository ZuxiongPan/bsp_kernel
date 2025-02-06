#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <linux/netlink.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <ukcomm/comm_netlink.h>

const char *msg = "Hello from user space";

int main(void)
{
    struct sockaddr_nl srcAddr, destAddr;
    struct nlmsghdr *nlHeader = NULL;
    struct iovec iov;
    struct msghdr msgHeader;
	int sockFd;
	char buffer[NETLINK_MESSAGE_MAXLEN];

	printf("user: current pid is %d\n", getpid());
    sockFd = socket(AF_NETLINK, SOCK_RAW, NETLINK_PZXPROTOCOL);
    if (sockFd < 0)
	{
        perror("create netlink socket");
        return -1;
    }

    memset(&srcAddr, 0, sizeof(srcAddr));
    srcAddr.nl_family = AF_NETLINK;
    srcAddr.nl_pid = getpid();

    if (bind(sockFd, (struct sockaddr *)&srcAddr, sizeof(srcAddr)) < 0)
	{
        perror("bind netlink socket");
        close(sockFd);
        return -1;
    }
	
	memset(&destAddr, 0, sizeof(destAddr));
	destAddr.nl_family = AF_NETLINK;
	destAddr.nl_pid = 0;
	
	nlHeader = (struct nlmsghdr*)buffer;
	nlHeader->nlmsg_len = NETLINK_MESSAGE_MAXLEN;
	nlHeader->nlmsg_type = 0;
	nlHeader->nlmsg_flags = 0;
	nlHeader->nlmsg_pid = getpid();
	memcpy(NLMSG_DATA(nlHeader), msg, strlen(msg) + 1);
	
	iov.iov_base = (void*)nlHeader;
	iov.iov_len = nlHeader->nlmsg_len;
	msgHeader.msg_name = (void*)&destAddr;
	msgHeader.msg_namelen = sizeof(destAddr);
	msgHeader.msg_iov = &iov;
	msgHeader.msg_iovlen = 1;
	
	if(sendmsg(sockFd, &msgHeader, 0) < 0)
	{
		perror("send netlink message failed\n");
		close(sockFd);
		return -1;
	}
	
	do {
		if(recvmsg(sockFd, &msgHeader, 0) < 0)
		{
			perror("receive netlink message failed\n");
			continue;
		}
		
		printf("receive message length from kernel: %d\n", nlHeader->nlmsg_len);
		printf("receive message from kernel: %s\n", (char*)NLMSG_DATA(nlHeader));
		break;
	} while(1);

    close(sockFd);
    return 0;
}