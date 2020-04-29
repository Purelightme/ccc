//
// Created by purelightme on 2020/4/25.
//

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *args[]){
    FILE *fp;
    fp = fopen("test.txt","rb");
    if (fp == NULL)
    {
    	fprintf(stderr, "错误号：%d\n", errno);
    	perror("错误");
    	fprintf(stderr, "%s\n", strerror(errno));
    	return EXIT_FAILURE;
    }else{
    	fclose(fp);
    }
    return EXIT_SUCCESS;
}