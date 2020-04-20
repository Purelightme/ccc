#include<stdio.h>

int read_file(char path[20]){
	FILE *fp = NULL;
	fp = fopen(path,"r");
	char data[8192];
	if (fp == NULL)
	{
		perror("文件打开失败：\n");
		return -1;
	}
	fgets(data,8192,fp);
	fclose(fp);
	printf("%s\n", data);
	return 0;
}


int main(){
	char contents[30] = "";
	char path[30] = "test.log";
	FILE *fd = NULL;

	printf("请输入内容：\n" );
	scanf("%s",contents);

	fd = fopen(path,"w+");
	if (fd == NULL)
	{
		perror("打开文件失败：" );
	}
	fputs(contents,fd);
	fclose(fd);
	printf("完成写入\n");
	read_file(path);
	return 0;
}