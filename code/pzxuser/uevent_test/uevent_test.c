#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <linux/netlink.h>

#define NETLINK_CUSTOM 31  // 需要与内核端匹配
#define MAX_PAYLOAD 1024   // 消息的最大长度

void send_netlink_message(int sock, struct sockaddr_nl *dest_addr, const char *message) {
    struct nlmsghdr *nlh;
    struct iovec iov;
    struct msghdr msg;

    // 分配 Netlink 消息缓冲区
    nlh = (struct nlmsghdr *)malloc(NLMSG_SPACE(MAX_PAYLOAD));
    memset(nlh, 0, NLMSG_SPACE(MAX_PAYLOAD));

    // 设置 Netlink 消息头
    nlh->nlmsg_len = NLMSG_SPACE(strlen(message) + 1);
    nlh->nlmsg_pid = getpid();  // 发送进程的 PID
    nlh->nlmsg_flags = 0;
    strcpy(NLMSG_DATA(nlh), message);

    // 设置 iovec 结构体
    iov.iov_base = (void *)nlh;
    iov.iov_len = nlh->nlmsg_len;

    // 设置 msghdr 结构体
    memset(&msg, 0, sizeof(msg));
    msg.msg_name = (void *)dest_addr;
    msg.msg_namelen = sizeof(*dest_addr);
    msg.msg_iov = &iov;
    msg.msg_iovlen = 1;

    // 发送消息到内核
    if (sendmsg(sock, &msg, 0) < 0) {
        perror("sendmsg");
    } else {
        printf("Sent Netlink message: %s\n", message);
    }

    free(nlh);
}

int main() {
    int sock;
    struct sockaddr_nl src_addr, dest_addr;
	char data[1024];
	char buffer[1024];

    // 创建 Netlink 套接字
    sock = socket(PF_NETLINK, SOCK_RAW, NETLINK_KOBJECT_UEVENT);
    if (sock < 0) {
        perror("socket");
        return -1;
    }

    // 初始化源地址
    memset(&src_addr, 0, sizeof(src_addr));
    src_addr.nl_family = AF_NETLINK;
    src_addr.nl_pid = getpid();  // 进程 PID
	src_addr.nl_groups = 1;

    // 绑定 socket
    if (bind(sock, (struct sockaddr *)&src_addr, sizeof(src_addr)) < 0) {
        perror("bind");
        close(sock);
        return -1;
    }

    // 初始化目标地址（内核）
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.nl_family = AF_NETLINK;
    dest_addr.nl_pid = 0;   // 0 表示发送到内核
    dest_addr.nl_groups = 0;

	int i = 0;
    // 发送 Netlink 消息到内核
	do {
		snprintf(data, 1024, "message %d from user space.", i);
		send_netlink_message(sock, &dest_addr, data);
		sleep(3);
		i++;
	} while(i < 3);
	
	i = 0;
	while(1)
	{
		ssize_t len = recv(sock, buffer, sizeof(buffer) - 1, 0);
		if(len < 0)
		{
			perror("receive uevent message from kernel failed!");
			continue;
		}
		
		snprintf(data, 1024, "receive message %d from user space.", i++);
		send_netlink_message(sock, &dest_addr, data);
		buffer[len] = '\0';
		printf("receive uevent message: %s\n", buffer);
	}

    close(sock);
    return 0;
}


/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <linux/netlink.h>

#define BUFFER_SIZE 4096
#define logpre "uevent user: "

int main()
{
	int sockFd = socket(AF_NETLINK, SOCK_RAW, NETLINK_KOBJECT_UEVENT);
	if(sockFd < 0)
	{
		perror(logpre "create socket failed!");
		return -1;
	}
	
	struct sockaddr_nl nlAddr;
	char buffer[BUFFER_SIZE];
	
	memset(&nlAddr, 0, sizeof(struct sockaddr_nl));
	nlAddr.nl_family = AF_NETLINK;
	nlAddr.nl_pid = getpid();
	nlAddr.nl_groups = 1;
	
	if(bind(sockFd, (struct sockaddr *)&nlAddr, sizeof(struct sockaddr_nl)) < 0 )
	{
		perror(logpre "bind socket fd failed!");
		close(sockFd);
		return -1;
	}
	
	printf(logpre "pid %d Listening uevent from kernel ...\n", getpid());
	
	while(1)
	{
		ssize_t len = recv(sockFd, buffer, sizeof(buffer) - 1, 0);
		if(len < 0)
		{
			perror(logpre "receive uevent message from kernel failed!");
			continue;
		}
		
		buffer[len] = '\0';
		printf(logpre "receive uevent message: %s\n", buffer);
	}
	
	close(sockFd);
	
	return 0;
}
*/