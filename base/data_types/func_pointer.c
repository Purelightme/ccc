#include<stdio.h>

int max(int a,int b){
	if (a > b)
	{
		return a;
	}else{
		return b;
	}
}

int main(int argc, char const *argv[])
{
	int (*p)(int,int) = max;
	int a,b,c;
	printf("请输入三个整数:\n");
	scanf("%d,%d,%d",&a,&b,&c);
	int d = p(p(a,b),c);
	printf("最大的是：%d\n", d);
	return 0;
}