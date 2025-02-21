#ifndef __NETLINK_MSGID__
#define __NETLINK_MSGID__

/* msgId info:
bits	31-28	27-16	15-0
mean	type	module	id
*/
#define MAKE_MSGHEADER(type, module) \
	((((type) & 0xf) << 28) | ((module & 0xfff) << 16))
	
#define GET_NLMSG_TYPE(id) (((id) >> 28) & 0xf)
#define GET_NLMSG_MODULE(id) (((id) >> 16) & 0xfff)

#define TEST_NLMSG_TYPE 0x8

#define TEST_NLMSGHEADER MAKE_MSGHEADER(TEST_NLMSG_TYPE, 0x5af)
#define TEST_NLMSG (TEST_NLMSGHEADER + 1)

#endif
