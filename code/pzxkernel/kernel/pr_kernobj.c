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

void print_filesystem(void *pobj)
{
	PTR_INVALID_RET(pobj, "struct file_system_type");
	
	struct file_system_type *pFsType = (struct file_system_type*)pobj;
	printk("struct file_system_type members:\n");
	printk("name: %s\n", ptrstr(pFsType->name));
	
	return ;
}

