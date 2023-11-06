#include <stdlib.h>
#include <stdio.h>

void* btc_malloc(size_t size) {
    void *ptr = malloc(size);
    
    if (ptr == NULL) {
        printf("Error: Unable to allocate memory!\n");
        exit(EXIT_FAILURE);
    }
    
   return ptr;
}