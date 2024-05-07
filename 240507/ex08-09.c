#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
    pid_t pid;

    if((pid = fork()) > 0) {
	sleep(1);
	exit(1);
    }
    else if(pid == 0) {
	printf("old session : %d\n", getsid(0));
	printf("new session : %d\n", setsid());
	sleep(600);
    }
}
