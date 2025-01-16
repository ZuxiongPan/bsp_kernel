#include <linux/init.h>
#include <linux/module.h>

static int __init virt_init(void)
{
	printk("[%s]: %d\n", __FUNCTION__, __LINE__);
	
	return 0;
}

static void __exit virt_exit(void)
{
	printk("[%s]: %d\n", __FUNCTION__, __LINE__);
	
	return ;
}

module_init(virt_init);
module_exit(virt_exit);

MODULE_LICENSE("GPL");