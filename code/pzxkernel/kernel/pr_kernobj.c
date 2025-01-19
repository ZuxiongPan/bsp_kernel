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
			
#define prefix "[kernobj]"

void print_filesystem(void *pobj)
{
	PTR_INVALID_RET(pobj, "struct file_system_type");
	
	struct file_system_type *pFsType = (struct file_system_type*)pobj;
	printk(prefix"struct file_system_type members:\n");
	printk("\tname: %s\n", ptrstr(pFsType->name));
	printk("\tfs_flags: 0x%x\n", pFsType->fs_flags);
	printk("\tfs_parameter_spec pos: 0x%llx\n", ptr_to_hex(pFsType->parameters));
	
	return ;
}

