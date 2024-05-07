#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    printf("%s\n", getenv("APPLE"));
    unsetenv("APPLE");

    if(!getenv("APPLE"))
	printf("APPLE not Found..\n");
}

