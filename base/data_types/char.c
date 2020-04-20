#include<stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char a[2] = "a";
	char b[6] = "hello";
	for (int i = 0; i < strlen(a); ++i)
	{
		printf("%c\n", a[i]);
	}
	printf("---------\n");
	for (int i = 0; i < strlen(b); ++i)
	{
		printf("%c\n", b[i]);
	}
	printf("---------\n");
	for (int i = 0; i < 2; ++i)
	{
		printf("%c\n", a[i]);	
	}
	printf("end\n");
	return 0;
}