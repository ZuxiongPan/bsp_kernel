#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <string.h>
#include <ukcomm/comm_ioctl.h>

const char devname[] = "/dev/virtdev";
const char optstr[] = "p:";

static void print_usage(void)
{
	printf("appctl\tusage: limited control of kernel for user\n");
	printf("\t-p [p_option]: print information of kernel\n");
	printf("\t\t[filesystems]: print filesystems registered in kernel\n");
}

static unsigned int cmd_print(const char *arg)
{
	unsigned int ret = 0;
	
	if(strcmp(arg, "filesystems") == 0)
		ret = VIRTIOCTL_PR_FILESYSTEMS;
	
	return ret;
}

int main(int argc, char **argv)
{
	int ret = 0;
	int opt, cmd;
	
	if((argc < 2) || (strcmp(argv[1], "--help") == 0))
	{
		print_usage();
		return ret;
	}
	
	int fd = open(devname, O_RDWR);
	if(fd < 0)
	{
		printf("open device %s failed\n", devname);
		return -1;
	}
	
	opt = getopt(argc, argv, optstr);
	while((opt != -1) && (ret == 0))
	{
		switch (opt)
		{
			case 'p':
				cmd = cmd_print(optarg);
				ret = ioctl(fd, cmd, 0);
				if(ret < 0)
					printf("ioctl device %s error, ioctl cmd %x\n", devname, cmd);
				break;
			default:
				print_usage();
				break;
		}
		opt = getopt(argc, argv, optstr);
	}
	
	close(fd);
	return ret;
}