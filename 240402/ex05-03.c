#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    DIR *dirp;
    if((dirp = opendir("test_dir1")) == NULL) {
	fprintf(stderr, "Error on opening directiry test_dir1\n");
	exit(1);
    }

    closedir(dirp);
}
