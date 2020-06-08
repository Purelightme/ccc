#include<stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	struct tm t;
	time_t timestamp;
	char s[100];
	t.tm_year = 2020 - 1900;
	t.tm_mon = 5 - 1;
	t.tm_mday = 1;
	// t.tm_isdst = -1;
	t.tm_hour = 0;
    t.tm_min = 0;
    t.tm_sec = 1;
	timestamp = mktime(&t);
	strftime(s,100,"%Y-%m-%d %H:%M:%S",&t);
	printf("时间：%s\n", s);
	printf("时间戳：%ld\n", timestamp);
	return 0;
}