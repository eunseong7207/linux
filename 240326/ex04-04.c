#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    char *filename = "b.txt";

    if(access(filename, F_OK) == -1) {
	fprintf(stderr, "FIle not Found.. %s\n", filename);
	exit(1);
    }
    
    printf("%s File is Exist\n", filename);
}
