#include <stdio.h>
#include <stdlib.h>

void* ldb_malloc(size_t size) {
    void *ptr = malloc(size);

    /* Rather than just aborting when ptr == NULL (failure of memory allocation),
    add some code to try again after a short delay,
    in hopes that some memory will have been freed up since the last try */

    if(!ptr) {
        delay(100);
        ptr = malloc(size);

        if(!ptr) {
            abort();
        }
    }

    return ptr;
} 

// Unfortunately, C does not have intrinsic delay function. Alternatively, we can set ptr to 0 in size 0 and insist at least one byte to be declared for non-0 sizes.

void* ldb_malloc(size_t size) {
    if (size == 0) {
        return 0; // ptr will always remain 0 when size is 0
    } 
    
    void *ptr; 
    do {
        ptr = malloc(size ? size : 1);

    } while (!ptr);

    return ptr;
}