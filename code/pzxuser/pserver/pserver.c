#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <linux/netlink.h>
#include <sys/socket.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <user/user_netlink.h>
#include <ukcomm/comm_netlink.h>
#include <ukcomm/comm_funcs.h>

#include "pserver.h"

static struct netlink_uobj uNetlinkObj;

int main(void)
{
	if(netlink_uobj_init(&uNetlinkObj) < 0)
	{
		printf("netlink_uobj init failed! exit!\n");
		return -1;
	}
	
	if(establish_connection(&uNetlinkObj) < 0)
	{
		printf("netlink establish connection failed\n");
		return -1;
	}
	
	while(1)
	{
	}

    close(uNetlinkObj.sockFd);
    return 0;
}
