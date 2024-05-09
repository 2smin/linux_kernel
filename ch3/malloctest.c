//include stdio string stdliba
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MEGABYTE 1024*1024

int main() {
    void *myblock = NULL;
    int count = 0;

    while(1) {
        myblock = (void *) malloc(MEGABYTE); //virtual mem 할당
        if(!myblock) {
            printf("Error: Out of memory\n");
            break;
        }
        printf("%d MB allocated\n", ++count*MEGABYTE);
        // memset(myblock, 1, MEGABYTE); // 실제 메모리 공간 할당 (sa -r 로 확인 가능)
        sleep(1);
    }
    exit(0);
}