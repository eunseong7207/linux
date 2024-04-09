#include <stdio.h>
#include <unistd.h>

int main(void) {
    char *arg[] = {"ls", "-l", (char *)0};
    printf("before excuting ls -l\n");
    execv("/bin/ls", arg);
    printf("after excuting ls -l\n");
}

