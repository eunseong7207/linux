#include <stdio.h>

int main(void) {
    int n, box = 0;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
	box += i;
    }
    printf("%d\n", box);
    return 0;
}
