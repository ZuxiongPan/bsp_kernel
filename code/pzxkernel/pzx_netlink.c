#ifdef CONFIG_NET
#include <linux/netlink.h>
#include <linux/skbuff.h>
#include <net/sock.h>
#include <net/net_namespace.h>
#include <uapi/asm-generic/errno.h>
#include <linux/string.h>
#include <linux/delay.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/mutex.h>
#include <linux/timer.h>
#include <linux/kernel.h>
#include <kern/kern_log.h>
#include <ukcomm/comm_netlink.h>
#include <ukcomm/netlink_msgid.h>
#include <ukcomm/comm_funcs.h>

// use self-defined list
struct msg_node {
	unsigned char status;	// 0 - not received, 1 - received
	struct pzx_netlink_msg msg;
	struct msg_node *next;
};

static struct sock *pzxSock = NULL;
static DEFINE_MUTEX(queLock);
static struct msg_node *queue = NULL;
static struct timer_list queTimer;	// timer for clean message queue

static void add_message_to_queue(unsigned int msgId, unsigned int payloadLen, void *msgData)
{
	unsigned int payloadRealLen = payloadLen > MSG_PAYLOAD_MAXLEN ? MSG_PAYLOAD_MAXLEN : payloadLen;
	struct msg_node *pMsg = (struct msg_node *)kzalloc(sizeof(struct msg_node) + payloadRealLen, GFP_KERNEL);
	if(PTR_INVALID(pMsg))
	{
		kern_error("add message %x to queue failed!\n", msgId);
		return ;
	}
	
	pMsg->status = 0;
	pMsg->msg.msgId = msgId;
	pMsg->msg.payloadLen = payloadRealLen;
	if(payloadLen > 0)
		memcpy(pMsg->msg.payload, msgData, payloadRealLen);
	pMsg->next = NULL;
	
	mutex_lock(&queLock);
	pMsg->next = queue;
	queue = pMsg;	// add from header
	mutex_unlock(&queLock);
	
	return ;
}

static struct sk_buff* make_message(unsigned int msgId, unsigned int payloadLen, void *msgData)
{
	struct nlmsghdr *nlh;
	struct sk_buff *skb;
	unsigned int payloadRealLen = payloadLen > MSG_PAYLOAD_MAXLEN ? MSG_PAYLOAD_MAXLEN : payloadLen;
	
	// create netlink message
	skb = nlmsg_new(NETLINK_MESSAGE_MAXLEN, GFP_KERNEL);
	if(PTR_INVALID(skb))
	{
		kern_error("alloc skbuff failed!\n");
		return NULL;
	}
	nlh = nlmsg_put(skb, 0, 0, 0, NETLINK_MESSAGE_MAXLEN, 0);
	if(PTR_INVALID(nlh))
	{
		kfree_skb(skb);
		kern_error("failed to put data into skbuff!\n");
		return NULL;
	}
	struct pzx_netlink_msg *pkmsg = (struct pzx_netlink_msg *)NLMSG_DATA(nlh);
	pkmsg->msgId = msgId;
	pkmsg->payloadLen = payloadRealLen;
	if(payloadLen > 0)
		memcpy(pkmsg->payload, msgData, payloadRealLen);
	
	return skb;
}

void kernel_asyn_msg(unsigned int msgId, unsigned int payloadLen, void *msgData)
{
	struct sk_buff* skb = make_message(msgId, payloadLen, msgData);
	if(PTR_INVALID(skb))
	{
		kern_error("message cannot send, id 0x%x.\n", msgId);
		return ;
	}
	
	add_message_to_queue(msgId, payloadLen, msgData);	// cache in queue
	netlink_broadcast(pzxSock, skb, 0, NTELINK_PZXGROUP, GFP_KERNEL);
	
	return ;
}
EXPORT_SYMBOL(kernel_asyn_msg);

static void queue_monitor(struct timer_list *timer)
{
	if(PTR_INVALID(queue))
	{
		kern_debug("the message queue is empty.\n");
		return ;	// empty queue no need to modify
	}
	
	mutex_lock(&queLock);
	kern_debug("message queue info:\n");
	struct msg_node *pos = queue;
	struct msg_node *next = pos->next;
	while(!PTR_INVALID(pos))
	{
		kern_debug("message id 0x%x, status %d, content:\n", pos->msg.msgId, pos->status);
		kern_hexdump(pos->msg.payload, pos->msg.payloadLen);
		if(pos->status)	// message needs release
		{
			struct msg_node *tmp = pos;
			if(pos == queue)	// queue head
				queue = next;
			kfree(tmp);
		}
		pos = next;
		next = pos ? pos->next : NULL;
	}
	mutex_unlock(&queLock);
	
	mod_timer(&queTimer, jiffies + msecs_to_jiffies(10000));
}

static void pzx_netlink_recv(struct sk_buff *skb)
{
	struct nlmsghdr *nlh = NULL;
	if(skb->len >= nlmsg_total_size(0))
	{
		nlh = nlmsg_hdr(skb);
		if((nlh->nlmsg_len < NLMSG_HDRLEN) || (skb->len < nlh->nlmsg_len))
			return ;
		
		struct pzx_netlink_msg *pumsg = NLMSG_DATA(nlh);
		
		// modify message queue that message has received
		mutex_lock(&queLock);
		struct msg_node *pos = queue;
		while(!PTR_INVALID(pos))
		{
			if(pos->msg.msgId == pumsg->msgId)
				pos->status = 1;	// the message with same id has received
			pos = pos->next;
		}
		mutex_unlock(&queLock);
		
		switch(pumsg->msgId)
		{
			default:
				// here means a message with data has been sent to user and user receive it success.
				kern_debug("message id 0x%x is received\n", pumsg->msgId);
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
		kern_error("netlink socket create failed, reason: no memory!\n");
		return -ENODEV;
	}

	timer_setup(&queTimer, queue_monitor, 0);
	mod_timer(&queTimer, jiffies + msecs_to_jiffies(10000));	// every 10s monitor queue
	
	kern_info("netlink socket create success!\n");
	
	return 0;
}

static void pzx_netlink_exit(struct net *net)
{
	if(!PTR_INVALID(pzxSock))
		netlink_kernel_release(pzxSock);
	
	del_timer(&queTimer);
	
	mutex_lock(&queLock);
	struct msg_node *pos = queue;
	while(!PTR_INVALID(pos))
	{
		struct msg_node *tmp = pos;
		pos = pos->next;
		kfree(tmp);
	}
	mutex_unlock(&queLock);
	
	kern_info("netlink release ok!\n");
	
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
