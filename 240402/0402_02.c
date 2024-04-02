#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int fileCount = 0;
int dirCount = 0;

int nameCheck(char* name) {
    DIR *dirp;
    if((dirp = opendir(name)) == NULL) {
	fileCount++;
    }
    else{
	dirCount++;
    }
}




int main(int argc, char* argv[]) {
    DIR *dirp;
    struct dirent *dentry;

    if((dirp = opendir(argv[1])) == NULL) {
	exit(1);
    }

    while(dentry = readdir(dirp)) {
	if(dentry->d_ino != 0) {
	    nameCheck(dentry->d_name);
	}
    }

    printf("File : %d\n", fileCount);
    printf("Dir : %d\n", dirCount);

    closedir(dirp);
}
