#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]) {
    pid_t pid;

    if((pid = fork()) > 0) {
	sleep(1);
	exit(1);
    }
    else if(pid == 0) {
	while(1) {
	    int fd;
	    time_t t = time(NULL);
	    char *buf = ctime(&t);
	    fd = open("curtiem.txt", O_RDWR | O_CREAT, 0644);
	    write(fd, buf, strlen(buf));
	    close(fd);
	    sleep(10);
	    setsid();
	}
    }
}
