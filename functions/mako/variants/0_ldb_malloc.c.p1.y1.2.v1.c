Variant 1:

#include <stdio.h>
size_t ldb_malloc(size_t size) {
    void *ptr = malloc(size);

    if (!ptr)
        exit(EXIT_FAILURE);

    return (size_t) ptr;
}


Variant 2:

#include <stdio.h>
void* ldb_malloc(size_t size) {
    void* ptr = malloc(size);

    if (ptr == ((void*)0)) 
        exit(1);
        
    return ptr;
}


Variant 3:

#include <string.h> 
void* ldb_malloc(size_t size) {
    void* ptr;

    ptr = calloc(size, 1);

    if (ptr == (void*)0) 
        exit(0);

    return ptr;
}


Variant 4:

#include <stdio.h> 
void* ldb_malloc(size_t size) {
    void* ptr = malloc(size);
     
    if (!ptr) 
        exit(255);  
     
    return ptr;
}


Variant 5:

#include <sys/types.h> 
void* ldb_malloc(size_t size) {
    void * ptr = malloc(size);

    if (ptr == NULL ) 
        _Exit(EXIT_FAILURE);

    return ptr;
}
