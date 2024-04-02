#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main(void) {
    DIR *dirp;
    struct dirent *dentry;

    if((dirp = opendir(".")) == NULL)
	exit(1);

    printf("FILE EXISTS..\n");
    while(dentry = readdir(dirp)) {
	if(dentry->d_ino != 0) 
	    printf("%s\n", dentry->d_name);
    }

    rewinddir(dirp);

    printf("removed File..\n");
    while(dentry = readdir(dirp)) {
	if(dentry->d_ino == 0) 
	    printf("%s\n", dentry->d_name);
    }

    closedir(dirp);
}

