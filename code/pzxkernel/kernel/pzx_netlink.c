#ifdef CONFIG_NET
#include <linux/netlink.h>
#include <linux/skbuff.h>
#include <net/sock.h>
#include <net/net_namespace.h>
#include <uapi/asm-generic/errno.h>
#include <linux/string.h>
#include <linux/delay.h>
#include <linux/init.h>
#include <ukcomm/comm_netlink.h>
#include <ukcomm/netlink_msgid.h>
#include <ukcomm/comm_funcs.h>

#define CONFIG_PZXNETLINK_TEST
#ifdef CONFIG_PZXNETLINK_TEST
#include <linux/timer.h>
#include <linux/kernel.h>

static struct timer_list sTimer;
#endif

#define fmt "[pzx netlink]: "

static struct sock *pzxSock = NULL;

static struct sk_buff* make_message(unsigned int msgId, unsigned int payloadLen, void *msgData)
{
	struct nlmsghdr *nlh;
	struct sk_buff *skb;
	unsigned int payloadRealLen = payloadLen > MSG_PAYLOAD_MAXLEN ? MSG_PAYLOAD_MAXLEN : payloadLen;
	
	// create netlink message
	skb = nlmsg_new(NETLINK_MESSAGE_MAXLEN, GFP_KERNEL);
	if(PTR_INVALID(skb))
	{
		pr_err(fmt "alloc skbuff failed!\n");
		return NULL;
	}
	nlh = nlmsg_put(skb, 0, 0, 0, NETLINK_MESSAGE_MAXLEN, 0);
	if(PTR_INVALID(nlh))
	{
		kfree_skb(skb);
		pr_err(fmt "failed to put data into skbuff!\n");
		return NULL;
	}
	struct pzx_netlink_msg *pkmsg = (struct pzx_netlink_msg *)NLMSG_DATA(nlh);
	pkmsg->msgId = msgId;
	pkmsg->payloadLen = payloadRealLen;
	if(payloadLen > 0)
		memcpy(pkmsg->payload, msgData, payloadRealLen);
	
	return skb;
}

// this function only send MSG_FUNCTIONAL
void kernel_asyn_msg(unsigned int msgId, unsigned int payloadLen, void *msgData)
{
	struct sk_buff* skb = make_message(msgId, payloadLen, msgData);
	if(PTR_INVALID(skb))
	{
		pr_err(fmt "message cannot send, id 0x%x.\n", msgId);
		return ;
	}
	
	netlink_broadcast(pzxSock, skb, 0, NTELINK_PZXGROUP, GFP_KERNEL);
	
	return ;
}

#ifdef CONFIG_PZXNETLINK_TEST
void sender_test(struct timer_list *timer)
{
	char buffer[MSG_PAYLOAD_MAXLEN];
	static unsigned int cnt = 0;
	static unsigned int id = TEST_NLMSG;
	
	pr_info(fmt "send times: %d\n", cnt++);
	
	snprintf(buffer, MSG_PAYLOAD_MAXLEN, "this is a message from kernel, id 0x%x.", id);
	kernel_asyn_msg(id, strlen(buffer) + 1, buffer);
	id += 8;
	
	mod_timer(&sTimer, jiffies + msecs_to_jiffies(5000));
}
#endif

static void pzx_netlink_recv(struct sk_buff *skb)
{
	struct nlmsghdr *nlh = NULL;
	if(skb->len >= nlmsg_total_size(0))
	{
		nlh = nlmsg_hdr(skb);
		if((nlh->nlmsg_len < NLMSG_HDRLEN) || (skb->len < nlh->nlmsg_len))
			return ;
		
		struct pzx_netlink_msg *pumsg = NLMSG_DATA(nlh);
		
		switch(pumsg->msgId)
		{
			default:
				// here means a message with data has been sent to user and user receive it success.
				pr_info(fmt "message id 0x%x is received\n", pumsg->msgId);
				break;
		}
	}
	
	return ;
}

static int pzx_netlink_init(struct net *net)
{
	struct netlink_kernel_cfg pzxCfg = {
		.input = pzx_netlink_recv,
		.groups = NTELINK_PZXGROUP,
	};
	
	pzxSock = netlink_kernel_create(net, NETLINK_PZXPROTOCOL, &pzxCfg);
	if(PTR_INVALID(pzxSock))
	{
		pr_err(fmt "netlink socket create failed, reason: no memory!\n");
		return -ENODEV;
	}
	
	pr_info(fmt "netlink socket create success!\n");

#ifdef CONFIG_PZXNETLINK_TEST
	timer_setup(&sTimer, sender_test, 0);
	mod_timer(&sTimer, jiffies + msecs_to_jiffies(3000));
#endif
	
	return 0;
}

static void pzx_netlink_exit(struct net *net)
{
	if(!PTR_INVALID(pzxSock))
		netlink_kernel_release(pzxSock);
	
	pr_info(fmt "netlink release ok!\n");
	
#ifdef CONFIG_PZXNETLINK_TEST
	del_timer(&sTimer);
#endif
	
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

