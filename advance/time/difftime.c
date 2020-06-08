#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	time_t start,end;
	time(&start);
	// sleep(3);
	int count = 0;
	for (int i = 0; i < 100; i++)
	{
		count += i;
	}
	time(&end);
	printf("共计用时：%f\n", difftime(end,start));
	printf("总和：%d\n", count);
	return 0;
}