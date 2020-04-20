#include<string.h>
#include<stdio.h>

int main(){
	char a[10];
	char b[10];
	printf("%s\n", "请输入第一个字符串：");
	scanf("%s",a);
	printf("%s\n", "请输入第二个字符串：");
	scanf("%s",b);
	printf("拼接结果：%s\n", strcat(a,b));
	return 0;
}