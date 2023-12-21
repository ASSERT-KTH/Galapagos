Here's the code variant with function's original functionality maintained.


#include <stdlib.h>

void *av_calloc(size_t nmemb, size_t size)
{
    void *ptr;
    if (nmemb == 0 || size == 0)
        return NULL;
        
    /* Bypassing size_mult function with direct multiplication, handled multiplication overflow check manually */
    if(size && nmemb > (SIZE_MAX / size)) 
        return NULL;
        
    ptr = av_mallocz(nmemb * size);
    if (ptr)
        memset(ptr, 0, nmemb * size);

    return ptr;
}
