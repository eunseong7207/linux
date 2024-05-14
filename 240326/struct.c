#include <stdio.h>

struct ABC {
    char a;
    int b;
    double c;
} ABC;

int main(void) {
    printf("%ld\n", sizeof(ABC));
    return 0;
}
