// common MACROS for userspace and kernel

#ifndef __COMM_IOCTL__
#define __COMM_IOCTL__

#define CUS_IOC(dir,type,nr,size) \
	(((dir) << 30) | ((type) << 8) | \
	 ((nr) << 0) | ((size) << 16))

#define CUS_IO(type,nr)		CUS_IOC(0U,(type),(nr),0)	// no data transfer
#define CUS_IOR(type,nr,size)	CUS_IOC(2U,(type),(nr),(sizeof(size)))	// user read kernel write
#define CUS_IOW(type,nr,size)	CUS_IOC(1U,(type),(nr),(sizeof(size)))	// user write kernel read
#define CUS_IOWR(type,nr,size)	CUS_IOC(3U,(type),(nr),(sizeof(size)))

struct kruw_data {
	unsigned int cmd;
};

struct kwur_data {
	unsigned int cmd;
};

#define VIRTIOCTL_NONE_BASE CUS_IO('v', 0)
#define VIRTIOCTL_PR_FILESYSTEMS (VIRTIOCTL_NONE_BASE + 1)

#endif