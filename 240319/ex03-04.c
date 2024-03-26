#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    int fdin, fdout;
    ssize_t nread;
    char buffer[1024];

    fdin = open("temp1.txt", O_RDWR, 0644);
    if(fdin == -1) {
	printf("fdin, file error\n");
	exit(1);
    }
    fdout = open("temp2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if(fdout == -1) {
	printf("fdout, file error\n");
	exit(1);
    }

    while((nread = read(fdin, buffer, 1024)) > 0) {
	if(write(fdout, buffer, nread) < nread) {
	    close(fdin);
	    close(fdout);
	}
    }

    close(fdin);
    close(fdout);
}
