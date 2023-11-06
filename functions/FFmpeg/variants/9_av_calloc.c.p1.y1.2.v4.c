Variant 1:

void *av_calloc(size_t nmemb, size_t size) 
{ 
    return av_mallocz(nmemb * size) ? : NULL;
}


Variant 2:

void *av_calloc(size_t nmemb, size_t size) 
{
    size_t result = nmemb * size;
    if (result == 0)
        return NULL; 
    return av_mallocz(result);
}


Variant 3:

void *av_calloc(size_t nmemb, size_t size)
{
    return (nmemb && size && (nmemb * size == size * nmemb))? av_mallocz(nmemb * size) : NULL;
}


Variant 4:

void *av_calloc(size_t nmemb, size_t size) 
{
    return !size_mult(nmemb, size, &result) ? NULL : av_mallocz(nmemb * size);
}
