#include <stdio.h>

int main(int argc, char const *argv[])
{
	char *str = "hahaNUL";
	char *s = NULL;
	printf("str=%s,s=%s",str,s);
	return 0;
}