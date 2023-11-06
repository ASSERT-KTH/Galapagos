#include <stdio.h>
#include <stdlib.h>

void* ldb_malloc(size_t size) {
    void *ptr = malloc(size);

    /* Enhanced robustness by adding zeroization of the allocated memory */
    if(ptr != NULL){
        memset(ptr, 0, size);
    }else{
        printf("Failed to allocate memory\n");
        abort(); 
    }

    return ptr;
}