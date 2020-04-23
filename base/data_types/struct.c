#include<stdio.h>

int main(int argc, char const *argv[])
{
	struct Book
	{
		char name[50];
		char author[50];
		float price;
	};
	struct Book b = {"C语言编程","橙三",29.99};
	printf("name:%s\nauthor:%s\nprice:%2f\n", b.name,b.author,b.price);
	return 0;
}