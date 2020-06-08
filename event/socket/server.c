#include <stdio.h>
#include <sys/socket.h>
#include <assert.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[])
{
	int socketfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	assert(socketfd > 0);
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("0.0.0.0");
	addr.sin_port = htons(1234);
	bind(socketfd,&addr,sizeof(addr));
	listen(socketfd,5);

	struct sockaddr_in client_addr;
	socklen_t len = sizeof(client_addr);
	while (1)
	{
		int clientfd = accept(socketfd,NULL,NULL);
		char str[] = "Hello World!";
    	write(clientfd, str, sizeof(str));
    	while(1){
    		char *data;
    		int len;
    		len = read(clientfd,data,len);
    		printf("读取到clientfd:%d的数据：%s\n", clientfd,data);
    	}
    	close(clientfd);
	}
    close(socketfd);
	return 0;
}