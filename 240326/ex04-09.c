#include <stdio.h>
#include <unistd.h>

int main(void) {
    char buffer[1024];
    int nread;

    nread = readlink("test.txt", buffer, 1024);
    write(1, buffer, nread);
}
