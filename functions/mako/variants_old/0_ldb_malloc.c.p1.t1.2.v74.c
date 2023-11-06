#include <stdio.h>
#include <stdlib.h>

void* ldb_malloc(size_t size) {
    void *ptr = malloc(size);

    if (ptr == NULL) {
        fprintf(stderr, "Failed to allocate memory.");
        exit(EXIT_FAILURE); // Exits the program with a status of failure.
    }

    return ptr;
}