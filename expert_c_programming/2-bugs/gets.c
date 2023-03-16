#include <stdio.h>

int main(int argc, char const *argv[])
{
	char line[2];
	gets(line);
	printf("line=%s", line);
	return 0;
}