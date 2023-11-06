Variant 1:

#include <stdlib.h>
#include <assert.h>

void* ldb_malloc(size_t size) {
    void *ptr = malloc(size);
    assert(ptr);
    return ptr;
}


Variant 2:

#include <stdlib.h>
#include <stdio.h>

void* ldb_malloc(size_t size) {
    void *ptr = malloc(size);
    if(ptr == NULL) {
        fprintf(stderr, "Out of memory!\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}


Variant 3:

#include <stdlib.h>

void* ldb_malloc(size_t size) {
    void *ptr = malloc(size);
    if(ptr == NULL) {
        perror("Error in malloc");
        exit(EXIT_FAILURE);
    }
    return ptr;
}


Variant 4:

#include <stdlib.h>

void* ldb_malloc(size_t size) {
    void *ptr = malloc(size);
    if(ptr == NULL) {
        exit(EXIT_FAILURE);
    }
    return ptr;
}
 

Variant 5:

#include <stdlib.h>

void* ldb_malloc(size_t size) {
    void *ptr = malloc(size);

    if (ptr == NULL) {
        fprintf(stderr, "Insufficient memory\n");
        exit(EXIT_FAILURE);
    }

    return ptr;
}
