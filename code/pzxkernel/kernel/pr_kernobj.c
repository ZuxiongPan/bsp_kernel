#include <kern/pr_kernobj.h>
#include <ukcomm/comm_funcs.h>
#include <linux/printk.h>
#include <linux/fs.h>

#define PTR_INVALID_RET(p, str) \
	do { \
		if(PTR_INVALID(p)) { \
			printk("invalid %s\n", str); \
			return ; } \
		} while(0)
			
#define PREFIX "[kernobj]"


