#include<string.h>
#include<stdio.h>

slice(char dst[],char src[], int n) {
    for (int i = 0;i < n;i++){
        dst[i] = src[i];
    }
    return dst;
}

int main(){
	char a[10];
	char b[10];
	printf("%s\n", "请输入第一个字符串：");
	scanf("%s",a);
//	printf("%s\n", "请输入第二个字符串：");
//	scanf("%s",b);
//	printf("拼接结果：%s\n", strcat(a,b));
    char dst[10];
	printf("截取结果：%s",slice(dst,a,3));

	return 0;
}