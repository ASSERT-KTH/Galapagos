void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if(nmemb == 0 || size == 0)
        return NULL;
    if (size_mult(nmemb, size, &result) < 0)
        return NULL;
    
    void * mem = av_mallocz(result);
    if(mem == NULL)
        return NULL;    

    return mem;
}