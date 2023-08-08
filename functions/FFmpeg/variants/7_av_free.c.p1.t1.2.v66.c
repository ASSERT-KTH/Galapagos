Here's a variant of the function maintaining original functionality while adding logging for memory desallocation - not changing original behavior. 


#include <stdio.h>

void av_free(void *ptr)
{
    printf("av_free invoked, pointer: %p\n", ptr);

#if HAVE_ALIGNED_MALLOC
    _aligned_free(ptr);
#else
    free(ptr);
#endif
}


This variant does the same memory allocation job, but also outputs a log message to stdout about the address of the memory being freed when the function is invoked.