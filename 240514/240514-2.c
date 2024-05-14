#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    sigset_t set;
    int count = 5;

    sigemptyset(&set);
    sigfillset(&set);

    sigprocmask(SIG_BLOCK, &set, NULL);

    while(count) {
	printf("don't distrub me(%d)\n", count--);
	sleep(1);
    }

    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sigprocmask(SIG_UNBLOCK, &set, NULL);

    printf("distrub me!\n");
}
