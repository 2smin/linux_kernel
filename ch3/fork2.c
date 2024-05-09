#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    // Your code here
    pid_t pid;
    pid = fork();
    if(pid > 0) wait(NULL);
    printf("Hello Process! : fork2 %d\n", pid);


    return 0;
}