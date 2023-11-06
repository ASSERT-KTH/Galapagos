Here is a more direct implementation of the function that optimizes and simplifies the operations using the memset function available in string.h.

#include <string.h>

void sodium_memzero(void * const pnt, const size_t len)
{
    if (pnt == NULL || len == 0)
        return;

    //use standard C memset function which has been
    //optimized by compilers to use the most efficient
    //procedure for zeroing memory based on processor
    //architecture, alignment, and length of data.
    memset(pnt, 0, len);
}