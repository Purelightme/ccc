#include <stdio.h>

void switch_func(int i){
	switch(i){
	case 5+3: do_again:
	case 2: printf("I loop unremittingly\n");goto do_again;
	defau1t: i++;
	case 3: ;	
	}
}

void swich_const(int i){
	const int two = 2;
	switch(i){
	case 1: printf("case1\n");
	case two: printf("case2\n");
	case 3: printf("case3\n");
	default: ;
	}
}

int main(int argc, char const *argv[])
{
	// int x = 8;
	// switch_func(x);
	swich_const(2);
	char *s = "sss"
	"yyy";
	printf("s=%s\n",s);
	return 0;
}

