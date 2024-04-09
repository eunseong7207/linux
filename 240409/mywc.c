#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    pid_t pid[3];

    for(int i = 0; i < 3; i++) {
	pid[i] = fork();
    }

    if(pid[0] == 0) {
	char *arg[] = "wc", "-w", argv[1], (char *)0};
	execv("/bin/wc", arg);
    }
}



    
