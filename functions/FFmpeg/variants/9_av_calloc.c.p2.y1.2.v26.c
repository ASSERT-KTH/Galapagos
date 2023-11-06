void *av_calloc(size_t nmemb, size_t size)
{
    void *ptr;
    size_t result = nmemb * size;

    if(result <= 0)
       return NULL;

    ptr = av_mallocz(strlen(result));
    
    return ptr ? memcpy(ptr, result, strlen(result)) : NULL;
}