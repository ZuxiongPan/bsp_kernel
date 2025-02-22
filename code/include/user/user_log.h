#ifndef __USER_LOG__
#define __USER_LOG__

#include <stdio.h>

#define USER_LOG_PRIORITY 0xa
#define USER_LOG_ERROR 0x2
#define USER_LOG_INFO 0x8
#define USER_LOG_DEBUG 0xe

#define user_log(prio, fmt, ...) \
	do { \
		if((prio) < USER_LOG_PRIORITY) \
			printf("[%s](%d)~" fmt, __FILE__, __LINE__, ##__VA_ARGS__); \
	} while(0)

#define user_error(fmt, ...) user_log(USER_LOG_ERROR, "Error: " fmt, ##__VA_ARGS__)
#define user_info(fmt, ...) user_log(USER_LOG_INFO, "Info: " fmt, ##__VA_ARGS__)
#define user_debug(fmt, ...) user_log(USER_LOG_DEBUG, "Debug: " fmt, ##__VA_ARGS__)

#endif