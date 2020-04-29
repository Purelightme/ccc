#include <stdio.h>

int factorial(int n){
	if (n > 1)
	{
		return n*factorial(n-1);
	}else{
		return n;
	}
}

int main(int argc, char const *argv[])
{
	printf("5!=%d\n", factorial(5));
	return 0;
}