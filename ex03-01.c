#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    int filedes, fdnew1, fdnew2;
    ssize_t nread;
    off_t newpos;

    char buffer[1024];
    char content[] = "Hello my friend!\n";

    filedes = open("data.txt", O_RDWR);

    nread = read(filedes, buffer, 1024);
    printf("%s", buffer);

    write(filedes, content, strlen(content));
    nread = read(filedes, buffer, 1024);
    printf("%s", buffer);

    close(filedes);

    fdnew1 = open("newdata1.txt", O_RDWR | O_CREAT, 0644);
    fdnew2 = creat("newdata2.txt", 0644);

    close(fdnew1); close(fdnew2);
    unlink("newdata2.txt");
}
