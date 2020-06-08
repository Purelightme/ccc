#include<stdio.h>
#include<sys/select.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
#include <pthread.h>


#define SERVER_PORT 8899
#define BUFFER_SIZE 50

void *handleMsg(clientfd) {
    while (1) {
        char data[BUFFER_SIZE];
        int len;
        len = read(clientfd, data, BUFFER_SIZE);
        if (len > 0) {
            printf("读取到clientfd:%d的数据：%s\n", clientfd, data);
            write(clientfd, data, len);
        } else if (len == 0) {
            printf("对端关闭\n");
            break;
        } else {
            printf("读数据出错");
            break;
        }
    }
}

int main(int argc, char const *argv[]) {
    int listenfd, clientfd, res;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(struct sockaddr);
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
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
    while (1) {
        clientfd = accept(listenfd, (struct sockaddr *) &client_addr, &client_addr_len);
        if (clientfd < 0) {
            perror("连接建立失败：");
            return -1;
        } else {
            printf("新连接：FD:%d,IP:%s,PORT:%d\n", clientfd, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        }

        pthread_t t;
        pthread_create(t,NULL,handleMsg,clientfd);
    }
    close(listenfd);
    return 0;
}