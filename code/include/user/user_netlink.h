#ifndef __USER_NETLINK__
#define __USER_NETLINK__

#define USER_NETLINKMSG_BUFLEN 128

// forward declaration
struct sockaddr_nl;	// linux/netlink.h
enum msg_type;	// ukcomm/comm_netlink.h
struct msghdr;	// sys/socket.h
struct iovec;	// sys/uio.h

struct netlink_uobj {
	unsigned char established;
	int pid;
	int sockFd;
	struct sockaddr_nl srcAddr;
	struct sockaddr_nl destAddr;
};

/*
	here we must point that user send netlink message to kernel, the message
	which doesn't append any data. This means enum msg_type can not be MSG_FUNCTIONAL.
	if we want to send data to kernel, we will use ioctl.
	
*/
int send_user_msg(const struct netlink_uobj *, enum msg_type, unsigned int);
int recv_kernel_msg(const struct netlink_uobj *, struct msghdr *, struct iovec *);

#endif