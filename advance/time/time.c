#include <stdio.h>
#include <time.h>

#define BST 0
#define CCT 8


int main(int argc, char const *argv[])
{
	time_t current_time;
	char str[80];
	// time(&current_time);
	// printf("当前时间：%s\n", ctime(&current_time));

	// current_time = time(NULL);
	// printf("当前时间戳：%ld\n", current_time);

	struct tm *now;
	time(&current_time);
	// now = gmtime(&current_time);
	now = localtime(&current_time);
    printf("时间：%d/%02d/%02d %02d:%02d:%02d\n", 
    	now->tm_year+1900,now->tm_mon+1,now->tm_mday,
    	(now->tm_hour)%24,now->tm_min,now->tm_sec
    	);
    // printf("周几：%d\n", now->tm_wday);
    // printf("今年已经过去%d天了\n", now->tm_yday);
    // printf("夏令时：%d\n", now->tm_isdst);
    printf("%s\n", asctime(now));
    printf("%lu\n", clock());

    strftime(str,80, "%Y-%m-%d %H:%M:%S",now);
    printf("%s\n", str);
	return 0;
}