#include<stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	union Sex {
		int a;
		float b;
		char c[20];
	};
	union Sex sex;
	sex.a = 1;
	printf("Sex.a:%d\n", sex.a);

	sex.b = 1.5;
	printf("Sex.b:%f\n", sex.b);


	strcpy(sex.c,"男的");
	// printf("union内存大小：%lu\n", sizeof(sex));
	printf("Sex.c:%s\n", sex.c);

	union Sex *p;
	p = &sex;
	printf("p->c：%s\n", p->c);
	return 0;
}