void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (!size || !nmemb || size_mult(nmemb, size, &result) < 0)
        return NULL;
    
    void *ptr = av_mallocz(result);
    
    if (!ptr)
        return NULL;
    
    return ptr;
}