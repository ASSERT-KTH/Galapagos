
#include <stdlib.h>

void* ldb_malloc(size_t size) {
    void *ptr = malloc(size);
    if (!ptr) {
        exit(EXIT_FAILURE); /* Unrecoverable error */
    }
    
    return ptr;
}
