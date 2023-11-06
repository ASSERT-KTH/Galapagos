#include <stdlib.h>
#include <stdio.h>

void* ldb_malloc(size_t size) {
    void *ptr = malloc(size);
    
    if (ptr == NULL) 
    {
        fputs("Failed to allocate memory, aborting.\n", stderr);
        abort();
    }
    
    return ptr;
}