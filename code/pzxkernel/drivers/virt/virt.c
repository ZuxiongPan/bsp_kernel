#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <ukcomm/comm_ioctl.h>

#define DEVICE_NAME "virtdev"

extern ssize_t devfop_defread(struct file *file, char __user *buf, size_t count, loff_t *ppos);
extern ssize_t devfop_defwrite(struct file *file, const char __user *buf, size_t count, loff_t *ppos);
extern void traverse_filesystem(void);

static dev_t devnum;
static struct cdev virtChrDev;
static struct class *virtClass;

static long virt_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	long ret = 0;
	
	switch(cmd)
	{
		case VIRTIOCTL_PR_FILESYSTEMS:
			traverse_filesystem();
			break;
		default:
			ret = -EINVAL;
			break;
	}
	
	return ret;
}

static const struct file_operations virtFops = {
    .owner = THIS_MODULE,
	.read = devfop_defread,
	.write = devfop_defwrite,
    .unlocked_ioctl = virt_ioctl,
};

static int __init virt_init(void)
{
    int ret;

    ret = alloc_chrdev_region(&devnum, 0, 1, DEVICE_NAME);
    if (ret) {
        pr_err("Failed to allocate device number\n");
        return ret;
    }

    cdev_init(&virtChrDev, &virtFops);
    virtChrDev.owner = THIS_MODULE;

    ret = cdev_add(&virtChrDev, devnum, 1);
    if (ret) {
        pr_err("Failed to add cdev\n");
        unregister_chrdev_region(devnum, 1);
        return ret;
    }

    virtClass = class_create(DEVICE_NAME);
    if (IS_ERR(virtClass)) {
        pr_err("Failed to create class\n");
        cdev_del(&virtChrDev);
        unregister_chrdev_region(devnum, 1);
        return PTR_ERR(virtClass);
    }

    if (!device_create(virtClass, NULL, devnum, NULL, DEVICE_NAME)) {
        pr_err("Failed to create device\n");
        class_destroy(virtClass);
        cdev_del(&virtChrDev);
        unregister_chrdev_region(devnum, 1);
        return -ENOMEM;
    }

    pr_info("virtual device initialized successfully\n");
    return 0;
}

static void __exit virt_exit(void)
{
    device_destroy(virtClass, devnum);
    class_destroy(virtClass);
    cdev_del(&virtChrDev);
    unregister_chrdev_region(devnum, 1);
    pr_info("virtual device unloaded\n");
}

module_init(virt_init);
module_exit(virt_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("pzx");
MODULE_DESCRIPTION("virt device for message change between kernel and user");