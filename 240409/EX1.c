#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid;
    int N, plus = 0, square = 1;
    scanf("%d", &N);

    pid = fork();

    if (pid == 0) {
        for (int i = 1; i <= N; i++) {
            square *= i;
        }
        printf("child process value : %d\n", square);
    } else if (pid > 0) {
        for (int i = 1; i <= N; i++) {
            plus += i;
        }
        wait(NULL);
        printf("parent process value : %d\n", plus);
    } else {
        printf("fail to fork\n");
    }

    return 0;
}

