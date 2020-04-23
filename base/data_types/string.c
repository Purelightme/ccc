#include<stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char greeting[10] = {'h','e','l','l','o','\0'};
	// printf("greeting:%s\n", greeting);
	char name[4] = {'s','c','l','\0'};
	char l = 'l';
	char n = 'n';
	char el[3] = {'e','l','\0'};
	char *lposition;
	char *nposition;
	char *elposition;

	// 返回第一次出现的指针
	lposition = strchr(greeting,l);
	nposition = strchr(greeting,n);
	elposition = strstr(greeting,el);

	// printf("strcat:%s\n", strcat(greeting,name));
	printf("strchr:%s\n", lposition);
	printf("strchr not exist:%s\n", nposition);
	printf("strstr:%s\n", elposition);
	printf("greeting length:%lu\n", strlen(greeting));
	return 0;
}