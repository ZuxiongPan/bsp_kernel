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
#include <ukcomm/comm_funcs.h>

#define fmt "[pzx netlink]: "

const char* msgTypeString[] = 
{
	[MSG_RECEIVED] = "message received",
	[MSG_ESTABLISH] = "message establish",
	[MSG_DISCONNECT] = "message disconnect",
	[MSG_FUNCTIONAL] = "message with data",
	[MSG_INVALID] = "invalid message",
};

static struct sock *pzxSock = NULL;
static pid_t userPid = -1;

static struct sk_buff* make_message(enum msg_type msgType, unsigned int msgId, \
	unsigned int payloadLen, void *msgData)
{
	struct nlmsghdr *nlHeader;
	struct sk_buff *skb;
	unsigned int payloadRealLen = (payloadLen > MSG_PAYLOAD_MAXLEN) ? MSG_PAYLOAD_MAXLEN : payloadLen;
	
	// create ack message
	skb = nlmsg_new(NETLINK_MESSAGE_MAXLEN, GFP_KERNEL);
	if(PTR_INVALID(skb))
	{
		pr_err(fmt"alloc skbuff failed!\n");
		return NULL;
	}
	nlHeader = nlmsg_put(skb, userPid, 0, 0, NETLINK_MESSAGE_MAXLEN, 0);
	if(PTR_INVALID(nlHeader))
	{
		kfree_skb(skb);
		pr_err(fmt"failed to put data into skbuff!\n");
		return NULL;
	}
	struct pzx_netlink_msg *pkmsg = (struct pzx_netlink_msg *)NLMSG_DATA(nlHeader);
	pkmsg->msgType = msgType;
	pkmsg->msgId = msgId;
	
	if(msgType == MSG_RECEIVED)
		pkmsg->payloadLen = 0;
	else if(msgType == MSG_FUNCTIONAL)
	{
		pkmsg->payloadLen = payloadLen;
		memcpy(pkmsg->payload, msgData, payloadRealLen);
	}
	
	return skb;
}

static void pzx_netlink_recv(struct sk_buff *skb)
{
	if(PTR_INVALID(skb))
	{
		pr_err(fmt"sk_buff is NULL!\n");
		return ;
	}
	
	struct nlmsghdr *nlHeader = nlmsg_hdr(skb);
	if(PTR_INVALID(nlHeader) || !nlmsg_ok(nlHeader, skb->len))
	{
		pr_err(fmt"netlink data is error!\n");
		return ;
	}
	
	struct pzx_netlink_msg *pumsg = (struct pzx_netlink_msg *)NLMSG_DATA(nlHeader);
	pr_info(fmt"receive message from user space: %s.\n", msgTypeString[pumsg->msgType]);

	switch(pumsg->msgType)
	{
		case MSG_ESTABLISH:
			if(userPid == -1)
			{
				userPid = nlHeader->nlmsg_pid;	// only set once
				struct sk_buff *skbRet = make_message(MSG_RECEIVED, pumsg->msgId, 0, NULL);
				if(!PTR_INVALID(skbRet))
				{
					pr_info(fmt"inform user space connect established.\n");
					netlink_unicast(pzxSock, skbRet, userPid, MSG_DONTWAIT);
				}
				else
					pr_err(fmt"make acknowledge message failed\n");
			}
			else
				pr_err(fmt"try to establish twice, current pid is %d, new pid is %d.\n", \
					userPid, nlHeader->nlmsg_pid);
			break;
		case MSG_DISCONNECT:
			userPid = -1;
			pr_info(fmt"message disconnect is received.\n");
			break;
		case MSG_RECEIVED:
			pr_info(fmt"message %x is received.\n", pumsg->msgId);
			break;
		case MSG_INVALID:
		default:
			pr_err(fmt"invalid message!\n");
			break;
	}
	
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
		pr_err(fmt"netlink socket create failed, reason: no memory!\n");
		return -ENODEV;
	}
	
	pr_info(fmt"netlink socket create success!\n");
	
	return 0;
}

static void pzx_netlink_exit(struct net *net)
{
	if(NULL != pzxSock)
		netlink_kernel_release(pzxSock);
	
	pr_info(fmt"netlink release ok!\n");
	
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

