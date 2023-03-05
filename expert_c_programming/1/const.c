#include <stdio.h>

int main(int argc, char const *argv[])
{
	 int limit = 10;
	 int * limitp = &limit;
	// const int limit = 10;
	// const int * limitp = &limit;
	int i = 27;
	limitp = &i;
	printf("limitp=%d",*limitp);
	*limitp = 30;
	printf("limitp=%d",*limitp);
	return 0;
}