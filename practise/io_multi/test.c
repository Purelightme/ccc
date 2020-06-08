#include <sys/select.h>
#include <stdio.h>

int main(){
    printf("%d",FD_SETSIZE);
    return 0;
}