#include <stdio.h>              // includes stdio library to use stderr and other related functions
#include <stdlib.h>             // includes stdlib library which utilize system related functions such as memory allocation, process control etc

void* ldb_malloc(size_t size)   // size_t data type is used to store size in bytes, it is usually used with sizeof() operator to capture the size of data types or variables 
{
    void *ptr;              // Initialized a pointer,
    ptr = malloc(size);     // allocate the memory of 'size' bytes and assignthe starting address of that block to ptr pointer

    if (ptr == NULL) {
        fprintf(stderr,"Memory allocation failed\n");  // If memory allocation fails, function malloc return NULL
        exit(EXIT_FAILURE);                            // Terminate program unsuccessfully
    }

    return ptr;          // return pointer to the allocated block
}