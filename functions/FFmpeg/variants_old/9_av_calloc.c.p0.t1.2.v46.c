void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if ((result = nmemb * size) <= 0)
        return NULL;
    void *ptr = av_mallocz(result);
    
    if(ptr == NULL)
        return NULL;
    else
        return ptr;
}