#include <stdlib.h>
#include <stdio.h>
#include "./Malloc.h"

void* Malloc(size_t size){
    void* num = malloc(size);
    if(!num){
        printf("failed to allocate memory");
        exit(1);
    }
    return num;
}

