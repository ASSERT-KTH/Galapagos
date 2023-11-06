#include <stddef.h>
#include <stdlib.h>

void* btc_malloc(size_t size) {
    void *ptr = malloc(size);
    if (!ptr) {
        fprintf(stderr, "Memory allocation failed. Terminating process.\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}
