void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (size_mult(nmemb, size, &result) < 0)
        return NULL;

    void* ptr = av_mallocz(result);
    
    if(ptr == NULL) // Additional fail-safe in case av_mallocz fails to allocate memory
        return NULL;
    
    return ptr;
}