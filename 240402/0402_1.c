#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    DIR *dirp;
    struct dirent *dentry;

    if((dirp = opendir(argv[1])) == NULL)
	exit(1);
    else
	printf("EXISTS!\n");

    closedir(dirp);
}
