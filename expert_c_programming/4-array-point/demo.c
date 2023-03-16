#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char *p = "abcd";
	p = "efg";
	printf("%s", p);
	// float *pp = 3.14;
	char a[] = "hello";
	strncpy(a, "wor", 3);
	printf("%s", a);
	return 0;
}