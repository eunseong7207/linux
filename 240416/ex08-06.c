#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    printf("[ex08-06.c] PPID : %d, PID : %d\n", getppid(), getpid());
}
