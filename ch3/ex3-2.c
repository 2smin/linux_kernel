#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // Your code here
    fork();
    fork();
    fork();
    printf("Hello Process! %d\n", getpid());
}