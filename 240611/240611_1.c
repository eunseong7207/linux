#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define SIZE 512

int main(void) {
    int N, M, sum = 0;
    char buffer[2];
    int filedes[2], nread;
    pid_t pid;

    scanf("%d %d", &N, &M);
    buffer[0] = N;
    buffer[1] = M;

    if(pipe(filedes) == -1) {
	printf("fail to call pipe()\n");
	exit(1);
    }

    if((pid = fork()) == -1) {
	printf("fail to call fork()\n");
	exit(1);
    }

    else if(pid > 0) {
	close(filedes[0]);
	write(filedes[1], buffer, SIZE);

	nread = read(filedes[0], buffer, SIZE);
    }
    else {
	close(filedes[1]);
	nread = read(filedes[0], sum, SIZE);
	printf("[child] %d\n", buffer[0]+buffer[1]);
    }
}
