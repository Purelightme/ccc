#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
	int a = 64;
	int A;
	A = tolower(a);
	printf("大写：%d\n", A);
	char c = A + '0';
	printf("大写：%c\n", c);
	return 0;
}