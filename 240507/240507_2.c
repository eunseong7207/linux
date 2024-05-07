#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    putenv("MYDATA=5");
    printf("%s\n", getenv("MYDATA"));
    execl("240507_3", "240507_3", (char *)0);
}
