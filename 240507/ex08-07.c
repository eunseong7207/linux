#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
    printf("getpgrp():%d\n", getpgrp());
    printf("getpgid():%d\n", getpgid(0));
    printf("getpgid(getpid()):%d\n", getpgid(getpid()));
    printf("getsid():%d\n", getsid(getpid()));
    return 0;
}
