#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <string.h>
#include <ukcomm/comm_ioctl.h>

#define PREV "[user]: "

const char devname[] = "/dev/virtdev";
const char optstr[] = "t:";

static void print_usage(void)
{
	printf("appctl\tusage: limited control of kernel for user\n");
	printf("\t-t [t_option]: test ioctl\n");
	printf("\t\t[nodata]: test ioctl without data\n");
	printf("\t\t[kwur]: test ioctl which read a string from kernel\n");
	printf("\t\t[kruw]: test ioctl which write a string to kernel\n");
	printf("\t\t[bidir]: test ioctl which write a string to kernel and then read a string from kernel\n");
}

static unsigned int cmd_test(const char *arg, struct ioctl_data *pdata)
{
	unsigned int ret = 0;
	const char userMsg[] = "this is a message from user";
	
	if(strcmp(arg, "nodata") == 0)
		ret = VIOCTL_NO_DATA;
	else if(strcmp(arg, "kwur") == 0)
		ret = VIOCTL_KWUR_STRING;
	else if(strcmp(arg, "kruw") == 0)
	{
		ret = VIOCTL_KRUW_STRING;
		strncpy(pdata->buf, userMsg, IOCTL_BUFSIZE);
		pdata->dataLen = strlen(pdata->buf) +1;
	}
	else if(strcmp(arg, "bidir") == 0)
	{
		ret = VIOCTL_BIDIR_STRING;
		strncpy(pdata->buf, userMsg, IOCTL_BUFSIZE);
		pdata->dataLen = strlen(pdata->buf) +1;
	}
	else
		ret = -1;
	
	printf(PREV"ioctl cmd is %x\n", ret);
	printf(PREV"ioctl data info: len is %d, data is %s\n", pdata->dataLen, pdata->buf[0] ? pdata->buf : "nul");
	return ret;
}

int main(int argc, char **argv)
{
	int ret = 0;
	int opt, cmd;
	struct ioctl_data udata;
	memset(&udata, 0, sizeof(struct ioctl_data));
	
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
			case 't':
				cmd = cmd_test(optarg, &udata);
				ret = ioctl(fd, cmd, &udata);
				if(ret < 0)
					printf("ioctl device %s error, ioctl cmd %x\n", devname, cmd);
				else
				{
					if(udata.dataLen != 0)
						printf(PREV"data info: len %d, content %s\n", udata.dataLen, udata.buf);
					else
						printf(PREV"here is no data\n");
				}
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