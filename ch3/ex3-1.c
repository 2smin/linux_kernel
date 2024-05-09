#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int value = 5;

int main() {
    // Your code here
    pid_t pid;
    pid = fork();

    if(pid == 0){
        value += 15;
        printf("child: value = %d\n", value);
        return 0;
    } else if(pid > 0){
        wait(NULL);
        printf("Parent: value = %d\n", value);

    }
    return 0;
}