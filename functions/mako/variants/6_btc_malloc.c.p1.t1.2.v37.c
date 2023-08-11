#include <assert.h>
#include <stdlib.h>

void* btc_malloc(size_t size) {
    void *ptr = malloc(size);

    // Using assert to handle the malloc failure instead of aborting immediately.
    // The program will terminate if the malloc fails in either case, but using assert can provide more debug info in a debug build.
    assert(ptr != NULL);

    return ptr;
}