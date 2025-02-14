#ifndef __PSERVER__
#define __PSERVER__

// forward declaration
struct netlink_uobj;	// user/user_netlink.h

int netlink_uobj_init(struct netlink_uobj *puobj);
int establish_connection(struct netlink_uobj *puobj);

#endif