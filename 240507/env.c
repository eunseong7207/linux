#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main(void) {
    while(*environ) {
	printf("%s\n", *environ++);
    }
}
