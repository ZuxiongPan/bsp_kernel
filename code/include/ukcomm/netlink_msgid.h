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

#define FILESYSTEM_NLMSG_MODULE 0x1

#define FS_NLMSGHEADER MAKE_MSGHEADER(0, FILESYSTEM_NLMSG_MODULE)
#define FS_NLMSG_MOUNT (FS_NLMSGHEADER + 1)

#endif
