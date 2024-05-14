#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>

int num = 0;

void int_handle(int);

int main(int argc, char *argv[]) {
    static struct sigaction act;
    act.sa_handler = int_handle;
    sigfillset(&(act.sa_mask));
    sigaction(SIGINT, &act, NULL);
    while(1) {
	printf("i'm sleepy..\n");
	sleep(1);
	if(num >= 1) {
	    exit(0);
	}
    }
}

void int_handle(int signum) {
    int fd;
    char *buf = "Good Bye!";
    ++num;
    fd = open("a.txt", O_RDWR | O_CREAT, 0644);
    write(fd, buf, strlen(buf));
    close(fd);
}
