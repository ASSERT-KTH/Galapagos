This version of av_free logs a debug message whenever it is called. This might be useful for debugging applications with complex memory allocating mechanisms. While this does not change the primary behaviour, it does change the ancillary behaviour of the program.


#include <stdio.h>

void av_free(void *ptr)
{
    printf("DEBUG: Freeing memory at %p\n", ptr);
    
#if HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
#else
    free(ptr);
#endif
}
