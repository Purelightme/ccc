#include<stdio.h>
#include<sys/event.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
#include <pthread.h>
#include <sys/types.h>

#define MAXEVENT 1024
#define SERVER_PORT 8899

int main(int argc, char const *argv[]) {
    int listenfd, res;
    struct sockaddr_in server_addr;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int)) < 0){
        perror("setsockopt 失败：");
        return -1;
    }

    if (listenfd < 0) {
        perror("socket创建失败：");
        return -1;
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("0.0.0.0");
    server_addr.sin_port = htons(SERVER_PORT);
    res = bind(listenfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (res < 0) {
        perror("bind失败：");
        return -1;
    }
    res = listen(listenfd, 20);
    if (res < 0) {
        perror("listen失败：");
        return -1;
    }

    int kq = kqueue();
    if (kq < 0) {
        perror("kqueue初始化失败：");
        return -1;
    }
    struct kevent *chlist; // 要监视的事件列表
    struct kevent *evlist; // kevent返回的事件列表（参考后面的kevent函数）
    chlist = (struct kevent *) malloc(sizeof(struct kevent));
    evlist = (struct kevent *) malloc(sizeof(struct kevent) * MAXEVENT);

    EV_SET(chlist, listenfd, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, 0);    //注册事件

    int nev, ready_fd;
    int clientfd;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(struct sockaddr);
    char buffer[1024];
    int nread;

    while (1) {
        nev = kevent(kq, chlist, 1, evlist, MAXEVENT, NULL);    //无限阻塞
        if (nev < 0) {
            perror("kevent");
            return -1;
        }
        if (nev == 0) {
            continue;
        }

        printf("nev:%d\n", nev);

        for (int i = 0; i < nev; i++) {
            ready_fd = evlist[i].ident;
            printf("fd:%d\n", ready_fd);

            if (ready_fd == listenfd) {
                //有新连接
                clientfd = accept(listenfd, (struct sockaddr *) &client_addr, &client_addr_len);
                if (clientfd < 0) {
                    perror("连接建立失败：");
                    return -1;
                } else if (clientfd > 0) {
                    printf("新连接：FD:%d,IP:%s,PORT:%d\n", clientfd, inet_ntoa(client_addr.sin_addr),
                           ntohs(client_addr.sin_port));
                    //加入监听
                    EV_SET(chlist, clientfd, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, 0);
                } else {
                    printf("不好了\n");
                }
            } else {
                //有连接发数据
                nread = read(ready_fd, buffer, 1024);
                if (nread < 0) {
                    perror("读数据出错：");
                    return -1;
                } else if (nread == 0) {
                    printf("对端关闭\n");
                    EV_SET(chlist, ready_fd, EVFILT_READ, EV_DELETE | EV_DISABLE, 0, 0, 0); //移出监听
                } else {
                    write(ready_fd, buffer, nread);
                }
            }
        }
    }
    close(listenfd);
    return 0;
}