#include <stdio.h>
#include "sum/sum.h"

int main(int argc, char const *argv[])
{
	int x = 2,y = 8,z;
	z = sum(x,y);
	printf("z=%d", z);
	return 0;
}