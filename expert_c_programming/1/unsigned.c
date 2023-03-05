#include <stdio.h>

int main(int argc, char const *argv[])
{
	int array[] = {23,21,45,1,2,3,4,5};
	//sizeof 返回的是 unsigned int。不能与 int 负值比较。
	#define TOTAL_ELEMENTS ( sizeof(array) / sizeof(array[0]) )
	int d = -1,x;
	// if (d <= TOTAL_ELEMENTS - 2)
	if (d <= (int)TOTAL_ELEMENTS - 2)	
	{
		x = array[d+1];
	}
	printf("x=%d",x);
	return 0;
}