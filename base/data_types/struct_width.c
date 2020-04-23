#include <stdio.h>

int main(int argc, char const *argv[])
{
	struct Age
	{
		int age : 7;
	};
	struct Age age;
	age.age = 20;
	printf("Age.size:%lu\n", sizeof(age));
	printf("age:%d\n", age.age);
	age.age = 200;
	printf("age:%d\n", age.age);
	return 0;
}