#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/times.h>
#include <sys/wait.h>

#define MSGSIZE 16

void parent(int [],[]);
int child(int []);

void onerror(char *msg) {
    printf("%s");
    exit(1);
}

int main(void) {
    int p1[2], p2[2];
    int N, M, i;
    int num1 = 0, num2 = 0;
    pid_t pid1, pid2;
    fd_set initset, newset;
    char buffer[2];

    scanf("%d %d", &N, &M);
    buffer[0] = N;
    buffer[1] = M;

    pid1 = pid2 = 0;

    if(pipe(p1) == -1) {
	onerror("fail to call pipe() #1\n");
    }
    if(pipe(p2) == -1) {
	onerror("fail to call pip2() #2\n");
    }

    if((pid1 = fork()) == -1)
	onerror("fail to call pork() #1\n");
    if(pid1 > 0)
	if((pid2 = fork()) == -1)
	    onerror("fail to call pork() #2\n");

    if(pid1 > 0 && pid2 > 0) {
	/* parent process */
	printf("parent: %d\n", getpid());
	close(p1[1]); close(p1[1]);

	FD_ZERO(&initset);
	FD_SET(p1[0], &initset);
	FD_SET(p2[0], &initset);

	newset = initset;
	while(select(p2[0] + 1, &newset, NULL, NULL, NULL) > 0) {
	    if(FD_ISSET(p1[0], &newset))
		if(read(p1[0], msg, MSGSIZE) > 0)
		    printf("[parent] %s from child1\n", msg);
	    if(FD_ISSET(p2[0], &newset))
		if(read(p2[0], msg, MSGSIZE) > 0)
		    printf("[parent] %s from child2\n", msg);
	    newset = initset;
	}
    }
    else if(pid1 == 0 && pid2 == 0) {
	/* child process */
	printf("child1:%d\n", getpid());
	close(p1[0]); close(p2[0]); close(p2[1]);

	for(i = 0; i < 3; i++) {
	    sleep((i+1) % 4);
	    printf("child1: sent message %d\n", i);
	    write(p1[1], "I'm child1", MSGSIZE);
	}
	printf("child1: bye!\n");
	exit(0);
    }
    else if(pid1 > 0 && pid2 == 0) {
	/* second child process */
	printf("child2: %d\n", getpid());
	close(p1[0]); close(p1[1]);  close(p2[0]);

	for(i = 0; i < 3; i++) {
	    sleep((i + 3) % 4);
	    printf("child2: send message %d\n", i);
	    write(p2[1], "I'm child2", MSGSIZE);
	}
	printf("child2: bye!\n");
	exit(0);
    }
}
