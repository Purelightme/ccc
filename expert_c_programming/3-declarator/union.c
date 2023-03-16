#include <stdio.h>

union bits32_tag {
	int whole;
	struct {
		char c0;
		char c1;
		char c2;
		char c3;
	} byte;
};

union bits32_tag value;

int main(int argc, char const *argv[])
{
	value.whole = 258;
	printf("%d,%d,%d,%d,%d\n",value.whole,value.byte.c0,value.byte.c1,value.byte.c2,value.byte.c3);
	return 0;
}