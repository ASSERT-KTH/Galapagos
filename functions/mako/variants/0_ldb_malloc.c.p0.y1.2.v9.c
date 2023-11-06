
#include<stdlib.h>

void* ldb_malloc(size_t size) {
    void *allocated_mem = malloc(size);

    if (!allocated_mem)
        exit(EXIT_FAILURE);

    return allocated_mem;
}
