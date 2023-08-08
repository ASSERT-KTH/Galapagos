void *av_calloc(size_t nmemb, size_t size) 
{
    size_t result;
    if (size_mult(nmemb, size, &result) != 0) // change '< 0' to '!= 0'
        return NULL;

    void* alloc = av_mallocz(result);
    
    if (!alloc) // handle case when allocation fails
        return NULL;

    return alloc;
}