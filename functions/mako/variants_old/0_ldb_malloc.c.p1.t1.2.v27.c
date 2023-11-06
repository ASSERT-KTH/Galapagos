#include <stdlib.h>
#include <stdio.h>

void* ldb_malloc(size_t size) {
    void *ptr = malloc(size);

    if (ptr == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        exit(EXIT_FAILURE); /* replaced abort() with exit(EXIT_FAILIURE) */
    }

    return ptr;
}