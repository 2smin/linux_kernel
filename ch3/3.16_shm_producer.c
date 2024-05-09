#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>

int main() {
    // Your code goes here
    
    const int SIZE = 4096;
    const char *name = "OS";
    const char *message_0 = "Hello";
    const char *message_1 = "World!";

    int fd; //fileDescriptor
    char *ptr; //pointer to shared memory

    fd = shm_open(name, O_CREAT | O_RDWR, 0666); //shared memory open

    ftruncate(fd, SIZE); //configure size of shm object

    ptr = (char *) mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0); //shm를 메모리에 매핑

    //메모리에 매핑된 pointer에다 message를 쓴다.
    sprintf(ptr, "%s", message_0); //write to the shared memory
    ptr += strlen(message_0); //포인터 증가

    sprintf(ptr, "%s", message_1);
    ptr += strlen(message_1);

    return 0;
}