#ifdef CONFIG_NET
#include <linux/netlink.h>
#include <linux/skbuff.h>
#include <net/sock.h>
#include <net/net_namespace.h>
#include <uapi/asm-generic/errno.h>
#include <linux/types.h>
#include <linux/string.h>
#include <linux/init.h>
#include <ukcomm/comm_netlink.h>

#define PREV "[pzx netlink]: "

static struct sock *pzxSock = NULL;
static pid_t userPid = 0;

const char *response = "Message received success!";

static void pzx_netlink_recv(struct sk_buff *skb)
{
	struct nlmsghdr *nlHeader;
	struct sk_buff *skbOut;
	struct nlmsghdr *nlHeaderOut;
	int msgLen = 0;
	
	nlHeader = nlmsg_hdr(skb);
	userPid = nlHeader->nlmsg_pid;
	
	pr_info(PREV"receive message from user space: %s, user pid: %d\n", (char*)NLMSG_DATA(nlHeader), userPid);
	
	msgLen = strlen(response) + 1;
	skbOut = nlmsg_new(NETLINK_MESSAGE_MAXLEN, GFP_KERNEL);
	if(NULL == skbOut)
	{
		printk(PREV"failed to alloc new skb memory\n");
		return ;
	}
	
	nlHeaderOut = nlmsg_put(skbOut, userPid, 0, 0, msgLen, 0);
	if(NULL == nlHeaderOut)
	{
		kfree_skb(skbOut);
		printk(PREV"failed to put netlink message\n");
		return ;
	}

	memcpy(NLMSG_DATA(nlHeaderOut), response, msgLen);
	
	netlink_unicast(pzxSock, skbOut, userPid, MSG_DONTWAIT);
	
	return ;
}

static int pzx_netlink_init(struct net *net)
{
	struct netlink_kernel_cfg pzxCfg = {
		.input = pzx_netlink_recv,
	};
	
	pzxSock = netlink_kernel_create(net, NETLINK_PZXPROTOCOL, &pzxCfg);
	if(NULL == pzxSock)
	{
		printk(PREV"netlink socket create failed, reason: no memory\n");
		return -ENODEV;
	}
	
	printk(PREV"netlink socket create success\n");
	
	return 0;
}

static void pzx_netlink_exit(struct net *net)
{
	if(NULL != pzxSock)
		netlink_kernel_release(pzxSock);
	
	printk(PREV"netlink release ok\n");
	
	return ;
}

static struct pernet_operations pzxNetlinkOps = {
	.init = pzx_netlink_init,
	.exit = pzx_netlink_exit,
};

static int __init pzx_netlink_socket_init(void)
{
	return register_pernet_subsys(&pzxNetlinkOps);
}

postcore_initcall(pzx_netlink_socket_init);

#endif	// CONFIG_NET

