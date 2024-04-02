#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    char name[1024];
    int nread;

    if(argc != 2)
	exit(1);

    nread = readlink(argv[1], name, 1024);

    printf("%s is %s a soft-link\n", argv[1], nread == -1 ? "not" : "");
}
