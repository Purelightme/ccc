#include <stdio.h>

struct s_tag
{
	int a[100];
};

struct s_tag orange,lime,lemon;

struct s_tag twofold(struct s_tag s)
{
	int j;
	for (int j = 0; j < 100; ++j)
	{
		s.a[j] *= 2;
	}
	return s;
}

int main(int argc, char const *argv[])
{
	int i;
	for (int i = 0; i < 100; ++i)
	{
		lime.a[i] = 1;
	}
	lemon = twofold(lime);
	orange = lemon;
	printf("%d,%d,%d\n", lime.a[0], lemon.a[0], orange.a[0]);
	return 0;
}