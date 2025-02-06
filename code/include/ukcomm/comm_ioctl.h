// common MACROS for userspace and kernel

#ifndef __COMM_IOCTL__
#define __COMM_IOCTL__

#define CUS_IOC(dir,type,nr,size) \
	(((nr) << 0) | ((type) << 8) | \
	 ((size) << 16) | ((dir) << 30))

#define CUS_IO(type,nr)		CUS_IOC(0U,(type),(nr),0)	// no data transfer
#define CUS_IOR(type,nr,size)	CUS_IOC(2U,(type),(nr),(sizeof(size)))	// user read kernel write
#define CUS_IOW(type,nr,size)	CUS_IOC(1U,(type),(nr),(sizeof(size)))	// user write kernel read
#define CUS_IOWR(type,nr,size)	CUS_IOC(3U,(type),(nr),(sizeof(size)))

#define IOCTL_BUFSIZE 512

struct ioctl_data {
	unsigned int dataLen;
	char buf[IOCTL_BUFSIZE];
};

#define VIOCTL_NONE_BASE CUS_IO('v', 0)
#define VIOCTL_NO_DATA (VIOCTL_NONE_BASE + 1)

#define VIOCTL_KWUR_BASE CUS_IOR('v', 0, struct ioctl_data)
#define VIOCTL_KWUR_STRING (VIOCTL_KWUR_BASE + 1)

#define VIOCTL_KRUW_BASE CUS_IOW('v', 0, struct ioctl_data)
#define VIOCTL_KRUW_STRING (VIOCTL_KRUW_BASE +1)

#define VIOCTL_BIDIR_BASE CUS_IOWR('v', 0, struct ioctl_data)
#define VIOCTL_BIDIR_STRING (VIOCTL_BIDIR_BASE +1)

#endif