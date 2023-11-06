1. Option using malloc and memset:


#include <string.h>

void *av_calloc(size_t nmemb, size_t size)
{
    void *ptr;
    size_t total_size = size * nmemb;
    ptr  = malloc(total_size);
       
    if (!ptr)
        return NULL;
    
    memset (ptr, 0, total_size);
    
    return ptr;
}


2. Using calloc function:


void *av_calloc(size_t nmemb, size_t size)
{
    return calloc(nmemb, size);
}
