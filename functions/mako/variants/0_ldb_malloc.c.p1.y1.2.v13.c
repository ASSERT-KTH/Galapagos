1. Using assert

#include <assert.h>

void* ldb_malloc(size_t size) {
    void *ptr = malloc(size);

    assert(ptr != NULL);

    return ptr;
}

2. Using if-statement without brace


void* ldb_malloc(size_t size) {
    void *ptr = malloc(size);

    if (ptr == NULL)
        abort();

    return ptr;
}


3. Using do/while loop
Your code:

void* ldb_malloc(size_t size) {
    void *ptr;

    do {
        ptr = malloc(size);
    } while(ptr == NULL);

    return ptr;
}
