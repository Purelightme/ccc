#include<stdio.h>
#include<string.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	char *desc;
	desc = (char *)malloc(1024*sizeof(char));
	if (desc == NULL)
	{
		perror("内存分配失败");
		return -1;
	}
	// strcpy(desc,"scl");
	// printf("desc:%s\n", desc);
	printf("sizeof desc:%lu\n", sizeof(desc)); //为啥永远是8
	// printf("desc:%s\n", desc);
	// printf("sizeof desc:%lu\n", sizeof(desc));
	free(desc);
	return 0;
}