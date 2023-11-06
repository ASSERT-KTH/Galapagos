Variant 1

#include<stddef.h>

void *av_calloc(size_t nmemb, size_t size)
{
    size_t mult;
    mult = nmemb * size;
    if (mult < 0)
        return NULL;
    
    return av_mallocz(mult);
}


Variant 2

#include<stddef.h>

void *av_calloc(size_t nmemb, size_t size)
{
    if (size && nmemb > SIZE_MAX / size)
        return NULL;

    return av_mallocz(size * nmemb);
}


Variant 3

#include<stddef.h>

void *av_calloc(size_t nmemb, size_t size)
{
    if (!size || (nmemb > SIZE_MAX / size)) 
        return NULL;
      
    return av_mallocz(nmemb * size);
}


Variant 4

#include<stddef.h>

void *av_calloc(size_t nmemb, size_t size)
{
    if (nmemb != 0 && size != 0)
    {
        size_t totalSize = nmemb * size;

        if(nmemb != totalSize / size)
          return NULL;

        return av_mallocz(totalSize);
    }

    return NULL;
}
