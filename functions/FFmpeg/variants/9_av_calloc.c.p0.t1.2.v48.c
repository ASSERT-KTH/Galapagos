void *av_calloc(size_t nmemb, size_t size)
{
    if (nmemb <= 0 || size <= 0)
        return NULL;

    size_t result = nmemb * size;
    void *ptr = av_mallocz(result);
    
    if (ptr == NULL)
        return NULL;
    
    return ptr;
}