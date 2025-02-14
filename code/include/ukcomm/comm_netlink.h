#ifndef __COMM_NETLINK__
#define __COMM_NETLINK__

#define NETLINK_PZXPROTOCOL 31
#define NETLINK_MESSAGE_MAXLEN 512

enum msg_type {
	MSG_RECEIVED,	// acknowledge a message, no data, no need to ack
	MSG_ESTABLISH,	// establish a link, no data, need to ack
	MSG_DISCONNECT,	// disconnect a link, no data, no need to ack
	MSG_FUNCTIONAL,	// msssage with data, need to ack
	MSG_INVALID,	// invalid message, no need to ack
};

struct pzx_netlink_msg {
	enum msg_type msgType;
	unsigned int msgId;
	unsigned int payloadLen;
	char payload[];
};

#define MSG_PAYLOAD_MAXLEN (NETLINK_MESSAGE_MAXLEN - sizeof(struct pzx_netlink_msg))

#define MSG_ESTABLISH_ID 0xffffffff

#endif