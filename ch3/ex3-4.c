#include <stdio.h>
#include <unistd.h>
#include <wait.h>


int main() {
    // Your code here

    pid_t pid, pid1;
    pid = 5;
    pid = fork();

    if(pid == 0){
        pid1 = getpid();
        printf("child: pid = %d\n", pid); // x
        printf("child: pid1 = %d\n", pid1); // child
    } else if(pid > 0){
        wait(NULL);
        pid1 = getpid();
        printf("Parent: pid = %d\n", pid); // child
        printf("Parent: pid1 = %d\n", pid1); //parent
    }
}
