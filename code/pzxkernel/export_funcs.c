#include <linux/fs.h>
#include <linux/mutex.h>

static char kernBuf[128];
static DEFINE_MUTEX(kernBufLock);

ssize_t devfop_defread(struct file *file, char __user *buf, size_t count, loff_t *ppos)
{
	ssize_t ret = 0;
	
	mutex_lock(&kernBufLock);
	ret = simple_read_from_buffer(buf, count, ppos, kernBuf, sizeof(kernBuf));
	mutex_unlock(&kernBufLock);
	
	return ret;
}
EXPORT_SYMBOL(devfop_defread);

ssize_t devfop_defwrite(struct file *file, const char __user *buf, size_t count, loff_t *ppos)
{
	ssize_t ret = 0;
	
	mutex_lock(&kernBufLock);
	ret = simple_write_to_buffer(kernBuf, sizeof(kernBuf), ppos, buf, count);
	mutex_unlock(&kernBufLock);
	
	return ret;
}
EXPORT_SYMBOL(devfop_defwrite);
