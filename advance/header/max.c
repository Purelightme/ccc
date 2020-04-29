#include <stdio.h>

#ifndef HEADER_MAX
#define HEADER_MAX true
#include "max.h"
#endif

#ifndef HEADER_MAX
#define HEADER_MAX true
#include "functions.h"
#endif

int max(int,int);

int main(int argc, char const *args[])
{
	int i = 4;
	int j = 6;
	int c;
	c = max(i,j);
	printf("max:%d\n", c);
	return 0;
}