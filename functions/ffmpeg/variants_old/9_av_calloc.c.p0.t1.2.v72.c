void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (size_mult(nmemb, size, &result) < 0)
        return NULL;
    
    void *allocated_memory = av_mallocz(result);
    
    if(allocated_memory == NULL)
        return NULL;
    
    return allocated_memory;
}