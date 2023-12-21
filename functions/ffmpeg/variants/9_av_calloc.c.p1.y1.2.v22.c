Variant 1:

void *av_calloc(size_t nmemb, size_t size)
{
    void *ptr;
    size_t bytes;
    
    if (size_mult(nmemb, size, &bytes) < 0)
        return NULL;

    ptr = av_mallocz(bytes);

    return ptr;
}


Variant 2:

void *av_calloc(size_t nmemb, size_t size)
{
    void *ptr = NULL;
    size_t result;
    
    if (size_mult(nmemb, size, &result) == 0)
        ptr = av_mallocz(result);

    return ptr;
}


Variant 3:

void *av_calloc(size_t nmemb, size_t size)
{
    void *ptr = NULL;

    if (nmemb && size) 
    {
        size_t result;
        if(size_mult(nmemb, size, &result) == 0)
            ptr = av_mallocz(result);
    }

    return ptr;
}
