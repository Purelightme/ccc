#include <assert.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int age;
	printf("请输入年龄:");
	scanf("%d",&age);
	assert(age > 18);
	printf("您的年龄是：%d\n", age);
	return 0;
}