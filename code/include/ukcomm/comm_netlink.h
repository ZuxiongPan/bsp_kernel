#ifndef __COMM_NETLINK__
#define __COMM_NETLINK__

#define NETLINK_PZXPROTOCOL 27
#define NTELINK_PZXGROUP 0x27
#define NETLINK_MESSAGE_MAXLEN 512

struct pzx_netlink_msg {
	unsigned int msgId;
	unsigned int payloadLen;
	char payload[];
};

#define MSG_PAYLOAD_MAXLEN (NETLINK_MESSAGE_MAXLEN - sizeof(struct pzx_netlink_msg))

#endif
