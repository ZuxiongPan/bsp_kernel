#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <linux/netlink.h>
#include <sys/socket.h>

#define UEVENT_BUFFER_SIZE 2048

int main(void) {
    struct sockaddr_nl sa;
    int sock;
    char buf[UEVENT_BUFFER_SIZE];
    int ret;

    // 创建 NETLINK_KOBJECT_UEVENT 套接字
    sock = socket(AF_NETLINK, SOCK_DGRAM, NETLINK_KOBJECT_UEVENT);
    if (sock < 0) {
        perror("socket");
        return -1;
    }

    // 初始化 sockaddr_nl
    memset(&sa, 0, sizeof(sa));
    sa.nl_family = AF_NETLINK;
    sa.nl_groups = 1; // 订阅多播组

    // 绑定套接字
    if (bind(sock, (struct sockaddr *)&sa, sizeof(sa)) < 0) {
        perror("bind");
        close(sock);
        return -1;
    }

    printf("Listening for uevents...\n");

    // 监听内核发来的事件
    while (1) {
        ret = recv(sock, buf, sizeof(buf), 0);
        if (ret < 0) {
            perror("recv");
            break;
        }

        // 打印事件数据
        buf[ret] = '\0'; // 确保字符串以 null 结尾
        printf("Received uevent:\n%s\n", buf);
    }

    close(sock);
    return 0;
}