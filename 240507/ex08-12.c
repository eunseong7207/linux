#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    char *envlist[] = {"APPLE=0", "BANANA=1", (char *)0};

    execle("ex08-13", "ex08-13", (char *)0, envlist);
}
