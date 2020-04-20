#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a = 1;
	int *b;
	b = &a;
	printf("a的地址：%p\n", &a);
	printf("b的地址：%p\n", b);
	printf("b指向的值：%d\n", *b);
	return 0;
}