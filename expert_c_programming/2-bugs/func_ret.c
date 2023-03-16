#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

char * localized_time(char * filename)
{
	struct tm *tm_ptr;
	struct stat stat_block;
	char buffer[120];
	stat(filename, &stat_block);
	// tm_ptr = localtime(&stat_block.st_mtime);
	// strftime(buffer, sizeof(buffer), "%a %b %e %T %Y", tm_ptr);
	printf("stat=%u", &stat_block.st_uid);

	return "xxx";
}

int main(int argc, char const *argv[])
{
	localized_time("./gets.c");
	return 0;
}