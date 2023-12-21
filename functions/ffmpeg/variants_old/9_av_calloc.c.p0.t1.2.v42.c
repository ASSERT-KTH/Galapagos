void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (size_mult(size, nmemb, &result) < 0)
        return NULL;
    
    void* memptr = av_mallocz(result);
    if(memptr == NULL)
        return NULL;
    
    return memptr;
}