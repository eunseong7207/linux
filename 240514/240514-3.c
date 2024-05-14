#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int main(void) {
    pid_t pid;
    int count = 5;

    if((pid = fork()) > 0) {
	sleep(2);
	printf("[parent] bye!\n");
    }
    else if(pid == 0) {
	kill(getppid(), SIGCHLD);
	printf("creat childe\n");
	printf("[childe] bye!\n");
	
    }
    else 
	printf("fail to fork\n");
}
