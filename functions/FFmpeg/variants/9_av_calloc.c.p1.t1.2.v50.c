void *av_calloc(size_t nmemb, size_t size)
{
    void *ptr;
    if(nmemb == 0 || size == 0)
    {
        return NULL;
    }
    ptr = av_mallocz(nmemb * size);

    if(ptr == NULL)
    {
        return NULL;
    }

    memset(ptr, 0, nmemb * size);
    return ptr;    
}