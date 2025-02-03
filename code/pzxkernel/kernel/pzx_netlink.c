#include <linux/netlink.h>
#include <linux/skbuff.h>
#include <net/sock.h>
#include <net/net_namespace.h>
#include <uapi/asm-generic/errno.h>
#include <ukcomm/comm_netlink.h>

#define PREV "pzx netlink: "

static struct sock *pzxSock = NULL;

static void pzx_netlink_recv(struct sk_buff *skb)
{
	pr_info("receive message\n");
	
	return ;
}

static int __init pzx_netlink_init(void)
{
	struct netlink_kernel_cfg pzxCfg = {
		.input = pzx_netlink_recv,
	};
	
	pzxSock = netlink_kernel_create(&init_net, NETLINK_PZXPROTOCOL, &pzxCfg);
	if(NULL == pzxSock)
	{
		printk(PREV"netlink socket create failed\n");
		return -ENOMEM;
	}
	
	printk(PREV"netlink socket create success\n");
	
	return 0;
}

static void __exit pzx_netlink_exit(void)
{
	if(NULL != pzxSock)
		netlink_kernel_release(pzxSock);
	
	printk(PREV"netlink release ok\n");
	
	return ;
}

module_init(pzx_netlink_init);
module_exit(pzx_netlink_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("pzx");
MODULE_DESCRIPTION("netlink socket");

