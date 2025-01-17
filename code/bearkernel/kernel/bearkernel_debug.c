#include <kernel/bearkernel_debug.h>
#include <linux/printk.h>

static inline unsigned char invalid_ptr(void *ptr)
{
	return (NULL == ptr);
}

static void print_filesystem(void *pobj)
{
	if(invalid_ptr(pobj))
		printk("invalid struct file_system_type\n");
	else
		printk("valid struct file_system_type\n");
	
	return ;
}

print_object pr_filesystem = print_filesystem;
