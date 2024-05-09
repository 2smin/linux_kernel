#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>

#include <sys/mman.h>
int main() 
{

    const int SIZE = 4096;
    const char *name = "OS";
    int fd;
    char *ptr;

    fd = shm_open(name, O_RDONLY, 0666);
    ptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    
    printf("%s", (char *)ptr); // shm에서 읽어오기

    shm_unlink(name); //shm 삭제

    return 0;
}