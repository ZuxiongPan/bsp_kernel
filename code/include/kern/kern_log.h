#ifndef __KERN_LOG__
#define __KERN_LOG__

#include <linux/printk.h>

#define KERNEL_LOG_PRIORITY 0xa
#define KERNEL_LOG_ERROR 0x2
#define KERNEL_LOG_INFO 0x8
#define KERNEL_LOG_DEBUG 0xe

#define KERNEL_HEXDUMP_VALID 0

#define kern_hexdump_implememt(ptr, size) \
	do { \
		if(KERNEL_HEXDUMP_VALID) \
			print_hex_dump(KERN_NOTICE, "", DUMP_PREFIX_ADDRESS, 16, 1, (void*)ptr, size, true); \
	} while(0)

#define kern_log(prio, fmt, ...) \
	do { \
		if((prio) < KERNEL_LOG_PRIORITY) \
			printk("[%s](%d)~" fmt, __FILE__, __LINE__, ##__VA_ARGS__); \
	} while(0)

#define kern_error(fmt, ...) kern_log(KERNEL_LOG_ERROR, "Error: " fmt, ##__VA_ARGS__)
#define kern_info(fmt, ...) kern_log(KERNEL_LOG_INFO, "Info: " fmt, ##__VA_ARGS__)
#define kern_debug(fmt, ...) kern_log(KERNEL_LOG_DEBUG, "Debug: " fmt, ##__VA_ARGS__)
#define kern_hexdump(ptr, size) kern_hexdump_implememt(ptr, size)
	

#endif