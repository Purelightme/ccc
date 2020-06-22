#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
#include <sys/epoll.h>
#include <sys/types.h>



#define SERVER_PORT 8899

int main(int argc, char const *argv[]) {
    int listenfd, res;
    struct sockaddr_in server_addr;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        perror("socket创建失败：");
        return -1;
    }
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int)) < 0){
        perror("setsockopt 失败：");
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

    struct epoll_event ev,events[20];

    int epfd = epoll_create(256);
    if(epfd < 0){
        perror("epoll_create失败:");
        return -1;
    }
    ev.data.fd = listenfd;
    ev.events = EPOLLIN|EPOLLET;
    epoll_ctl(epfd,EPOLL_CTL_ADD,listenfd,&ev);

    int nfds,i,clientfd,sockfd,n;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(struct sockaddr);
    int buffer_size = 1024;
    char buf[buffer_size];

    while (1) {
        nfds = epoll_wait(epfd,events,20,0);
        for ( i = 0; i < nfds; ++i) {
            if(events[i].data.fd == listenfd){
                clientfd = accept(listenfd,(struct sockaddr *)&client_addr,&client_addr_len);
                if(clientfd < 0){
                    perror("accept失败：");
                    return -1;
                }
                printf("新连接，IP：%s，端口：%d\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));
                ev.data.fd = clientfd;
                ev.events = EPOLLIN|EPOLLET;
                epoll_ctl(epfd,EPOLL_CTL_ADD,clientfd,&ev);
            } else if(events[i].events & EPOLLIN){
                sockfd = events[i].data.fd;
                if(sockfd < 0){
                    continue;
                }
                if ( (n = read(sockfd, buf, buffer_size)) < 0) {
                    printf("readline error\n");
                } else if (n == 0) {
                    close(sockfd);
                    printf("对端关闭\n");
                    events[i].data.fd = -1;
                }
                write(sockfd,buf,n);
            }
        }
    }
    close(epfd);
    return 0;
}