void *av_calloc(size_t nmemb, size_t size)
{
    if(nmemb == 0 || size == 0) 
        return NULL;

    size_t result = nmemb * size;
    if (result / size != nmemb) 
        return NULL;

    void* ptr = av_mallocz(result);
    if (ptr != NULL){
        memset(ptr, 0, result);
    }

    return ptr;
}