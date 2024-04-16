#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>

int main(void) {
    pid_t pid;
    int x, y, save = 1, sum = 0;
    int status;

    scanf("%d %d", &x, &y);

    pid = fork();

//    if(x > 10 || x < 1 || y < 1 || y > 10 || x < y) {
//	scanf("%d %d", &x, &y);
//    }

    if(pid > 0) {
	for(int i = 1; i <= y; i++) {
	    save *= x;
	}
	wait(&status);
	printf("result : %d\n", save + (status >> 8));
    }
    else if(pid == 0) {
	for(int i = x; i <= y; i++) {
	    sum += i;
	}
	exit(sum);
    }
    else 
    	printf("fail to forl\n");

 printf("good!\n");
}
	
	
