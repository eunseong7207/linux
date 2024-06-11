#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    sigset_t set;
    int count = 0;

    sigemptyset(&set);
    sigaddset(&set, SIGINT);

    sigprocmask(SIG_BLOCK, &set, NULL);

    while(1) {
	printf("I'm a child(%d)\n", count++);
	sleep(1);
	if(count == 5) {
	    sigprocmask(SIG_UNBLOCK, &set, NULL);
	}
    }
    printf("bye~\n");
}
