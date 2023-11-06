
#include <stdlib.h>

void *btc_malloc(size_t size) {
    void *ptr = malloc(size);

    if (ptr == NULL) {
        fprintf(stderr, "Failure to allocate memory.\n");   
        exit(EXIT_FAILURE);
    }

    return ptr;
}
