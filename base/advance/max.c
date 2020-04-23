#include <stdio.h>
#include "max.h"

int max(int,int);

int main(int argc, char const *argv[])
{
	int i = 4;
	int j = 6;
	int c;
	c = max(i,j);
	printf("max:%d\n", c);
	return 0;
}