#include <stdio.h>

int main(void) {
    int box = 0;

    for(int i = 1; i <= 100; i++) {
	box += i;
    }
    printf("%d\n", box);
    return 0;
}
