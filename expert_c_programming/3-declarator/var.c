#include <stdio.h>

char *(*c[2])(int **p);

char * add(int **i)
{
	char *s = "a";
	return s;
}

//p79
int main(int argc, char const *argv[])
{
	c[0] = add;
	char *t;
	// int i = 4;
	// int *j;
	// j = *i;
	// printf("%d",*j);
	int **q;
	// **q = *j;
	t = c[0](q);
	printf("%s", t);
	return 0;
}