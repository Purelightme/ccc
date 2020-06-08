#include<stdio.h>
#include<sys/select.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
#include <pthread.h>
#include <sys/select.h>


#define SERVER_PORT 8899

int main(int argc, char const *argv[]) {
    int listenfd, res;
    struct sockaddr_in server_addr;
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

    int client[FD_SETSIZE];
    for (int i = 0;i < FD_SETSIZE;i++){
        client[i] = -1;
    }
    int maxfd = listenfd;
    int maxi = -1;
    int i;
    int buffer_size = 1024;
    char buffer[buffer_size];

    fd_set rset,allset;
    FD_ZERO(&allset);
    FD_SET(listenfd,&allset);

    printf("ready!\n");

    while (1) {
        rset = allset;
        int nready = select(maxfd + 1,&rset,NULL,NULL,NULL);

        if(FD_ISSET(listenfd,&rset)){
            //有新连接
            int clientfd;
            struct sockaddr_in client_addr;
            socklen_t client_addr_len = sizeof(struct sockaddr);
            clientfd = accept(listenfd, (struct sockaddr *) &client_addr, &client_addr_len);
            if (clientfd < 0) {
                perror("连接建立失败：");
                return -1;
            } else {
                printf("新连接：FD:%d,IP:%s,PORT:%d\n", clientfd, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
            }
            for (int i = 0;i < FD_SETSIZE; i++){
                if(client[i] < 0){
                    client[i] = clientfd;
                    break;
                }
            }

            if(i == FD_SETSIZE){
                exit(-1);
            }
            FD_SET(clientfd,&allset);
            if(clientfd > maxfd){
                maxfd = clientfd;
            }
            if(i > nready){
                maxi = i;
            }
            if(--nready <= 0){
                continue;
            }
        }

        for (i = 0;i <= maxi; i++){
            int sockfd = client[i];
            if(sockfd < 0){
                continue;
            }
            if(FD_ISSET(sockfd,&rset)){
                int n = read(sockfd,buffer,buffer_size);
                if(n < 0){
                    close(sockfd);
                    printf("读取数据出错\n");
                    continue;
                }
                if(n == 0){
                    close(sockfd);
                    FD_CLR(sockfd,&allset);
                    client[i] = -1;
                    printf("对端关闭\n");
                } else{
                    write(sockfd,buffer,n);
                }
            }
            if(--nready == 0){
                break;
            }
        }
    }
    close(listenfd);
    return 0;
}