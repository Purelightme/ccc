#include <stdio.h>
#include <signal.h>

void max(int signal){
	printf("信号已触发\n");
}

int main(int argc, char const *argv[])
{
	void (*p)(int) = &max;
	signal(SIGINT,p);
	char a[10];
	printf("请输入信息：\n");
	scanf("%s",a);
	printf("a:%s\n", a);
	return 0;
}