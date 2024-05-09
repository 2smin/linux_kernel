#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(void){

    char write_msg[BUFFER_SIZE] = "Hello, World!";
    char read_msg[BUFFER_SIZE];

    int fd[2];
    pid_t pid;

    //pipe 생성
    if(pipe(fd) == -1){
        fprintf(stderr, "Pipe failed");
        return 1;
    }

    pid = fork();
    if(pid < 0){
        fprintf(stderr, "Fork failed");
        return 1;
    }

    if(pid > 0){
        //부모 프로세스
        close(fd[READ_END]); //write 만 할거임
        write(fd[WRITE_END], write_msg, strlen(write_msg)+1); //write to pipe
        close(fd[WRITE_END]); //write 끝
        printf("write to pipe: %s\n", write_msg);
    }
    else{
        //자식 프로세스
        close(fd[WRITE_END]); //read 만 할거임
        read(fd[READ_END], read_msg, BUFFER_SIZE); //read from pipe
        printf("read from pipe: %s\n", read_msg);
        close(fd[READ_END]); //read 끝
    }

    return 0;
}