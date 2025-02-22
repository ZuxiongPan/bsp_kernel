#ifndef __KERN_LOG__
#define __KERN_LOG__

#include <linux/printk.h>

#define KERNEL_LOG_PRIORITY 0xa
#define KERNEL_LOG_ERROR 0x2
#define KERNEL_LOG_INFO 0x8
#define KERNEL_LOG_DEBUG 0xe

#define kern_log(prio, fmt, ...) \
	do { \
		if((prio) < KERNEL_LOG_PRIORITY) \
			printk("[%s](%d)~" fmt, __FILE__, __LINE__, ##__VA_ARGS__); \
	} while(0)

#define kern_error(fmt, ...) kern_log(KERNEL_LOG_ERROR, "Error: " fmt, ##__VA_ARGS__)
#define kern_info(fmt, ...) kern_log(KERNEL_LOG_INFO, "Info: " fmt, ##__VA_ARGS__)
#define kern_debug(fmt, ...) kern_log(KERNEL_LOG_DEBUG, "Debug: " fmt, ##__VA_ARGS__)

#endif