In this variant, we will replace different memory clearing methods with only one - volatile pointer in a while loop. This change the behavior by making it consistent across all platforms (Windows, Linux, etc.) while maintaining original functionality of the function, which is secure memory cleansing.

This also simplifies the function greatly as C does not inherently have a way to prevent compiler's dead code elimination or optimization to possibly re-order memory operations or remove the memory zeroing code if it thinks nothing will check those memory bytes again, which could be occasionally unsafe for storing sensitive information. So, using volatile pointer allows us to tell the compiler that it should avoid any sort of optimizations and take it literally.

The following program let the volatile understand to the compiler those instructions will be act as they were adopted, regardless what inferences compiler may make based on the same program where they do not appear volatile:


#include <stddef.h>
void sodium_memzero(void * const pnt, const size_t len) {
    volatile char *volatile pnt_ = (volatile char *volatile) pnt;
    size_t i = (size_t) 0U;

    while (i < len) {
        pnt_[i++] = 0U;
    }
}
