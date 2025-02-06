#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <ukcomm/comm_ioctl.h>

#define DEVICE_NAME "virtdev"
#define PREV "[virt]: "

extern ssize_t devfop_defread(struct file *file, char __user *buf, size_t count, loff_t *ppos);
extern ssize_t devfop_defwrite(struct file *file, const char __user *buf, size_t count, loff_t *ppos);

static dev_t devnum;
static struct cdev virtChrDev;
static struct class *virtClass;

static long virt_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	long ret = 0;
	const char kernMsg[] = "this is a message from kernel";
	struct ioctl_data kdata;
	memset(&kdata, 0, sizeof(struct ioctl_data));
	
	printk(PREV"ioctl cmd is %x\n", cmd);
	
	switch(cmd)
	{
		case VIOCTL_NO_DATA:
			printk(PREV"here is no data transfer for ioctl\n");
			break;
		case VIOCTL_KWUR_STRING:
			printk(PREV"write data to user space\n");
			strncpy(kdata.buf, kernMsg, IOCTL_BUFSIZE);
			kdata.dataLen = strlen(kdata.buf) + 1;
			if(copy_to_user((void __user *)arg, &kdata, sizeof(struct ioctl_data)))
				return -EFAULT;
			break;
		case VIOCTL_KRUW_STRING:
			printk(PREV"read data to user space\n");
			if(copy_from_user(&kdata, (void __user *)arg, sizeof(struct ioctl_data)))
				return -EFAULT;
			printk("get data from user space: len %d, data %s\n", kdata.dataLen, kdata.buf[0] ? kdata.buf : "nul");
			break;
		case VIOCTL_BIDIR_STRING:
			if(copy_from_user(&kdata, (void __user *)arg, sizeof(struct ioctl_data)))
				return -EFAULT;
			printk("get data from user space: len %d, data %s\n", kdata.dataLen, kdata.buf[0] ? kdata.buf : "nul");
			printk(PREV"write data to user space\n");
			strncpy(kdata.buf, kernMsg, IOCTL_BUFSIZE);
			kdata.dataLen = strlen(kdata.buf) + 1;
			if(copy_to_user((void __user *)arg, &kdata, sizeof(struct ioctl_data)))
				return -EFAULT;
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