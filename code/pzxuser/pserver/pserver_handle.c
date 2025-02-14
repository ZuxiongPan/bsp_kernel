/*
	This file defines functions for pserver init and exit
*/
#include <sys/socket.h>
#include <sys/uio.h>
#include <linux/netlink.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <user/user_netlink.h>
#include <ukcomm/comm_netlink.h>
#include <ukcomm/comm_funcs.h>

#include "pserver.h"

int netlink_uobj_init(struct netlink_uobj *puobj)
{
	memset(puobj, 0, sizeof(*puobj));
	puobj->pid = getpid();
	puobj->sockFd = socket(AF_NETLINK, SOCK_RAW, NETLINK_PZXPROTOCOL);
	if(puobj->sockFd < 0)
	{
		perror("user: create netlink socket!");
		return -1;
	}

	puobj->srcAddr.nl_family = AF_NETLINK;
	puobj->srcAddr.nl_pid = getpid();
	if(bind(puobj->sockFd, (struct sockaddr *)(&puobj->srcAddr), sizeof(puobj->srcAddr)) < 0)
	{
		perror("user: bind netlink socket!");
		close(puobj->sockFd);
		return -1;
	}
	
	puobj->destAddr.nl_family = AF_NETLINK;
	puobj->destAddr.nl_pid = 0;	// pid 0 means kernel
	
	printf("netlink_uobj init success, pid is %d\n", puobj->pid);
	
	return 0;
}

int establish_connection(struct netlink_uobj *puobj)
{
	struct msghdr msgHeader;
	memset(&msgHeader, 0, sizeof(msgHeader));
    struct iovec iov;
	char buffer[NLMSG_SPACE(NETLINK_MESSAGE_MAXLEN)];
	struct nlmsghdr *nlHeader = (struct nlmsghdr*)buffer;
	
	iov.iov_base = buffer;
	iov.iov_len = NLMSG_SPACE(NETLINK_MESSAGE_MAXLEN);	

	if(send_user_msg(puobj, MSG_ESTABLISH, MSG_ESTABLISH_ID) < 0)
	{
		perror("user: send establish message failed!");
		close(puobj->sockFd);
		return -1;
	}
	while(!puobj->established)
	{
		if(recv_kernel_msg(puobj, &msgHeader, &iov) < 0)
		{
			perror("user: receive netlink message failed!");
			continue;
		}
		
		struct pzx_netlink_msg *pkmsg = (struct pzx_netlink_msg *)NLMSG_DATA(nlHeader);
		if(pkmsg->msgType == MSG_RECEIVED && pkmsg->msgId == MSG_ESTABLISH_ID)
			puobj->established = 1;
	}
	
	printf("user: establish connect success!\n");
	
	return 0;
}

