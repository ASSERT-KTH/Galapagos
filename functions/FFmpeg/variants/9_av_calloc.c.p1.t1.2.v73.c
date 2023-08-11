void *av_calloc(size_t nmemb, size_t size)
{
    if (nmemb == 0 || size == 0)
        return NULL;

    size_t result =  nmemb * size;

    /* Control overflow for large allocations */
    if(nmemb != 0 && result / nmemb != size)
        return NULL;

    void *ptr =  av_mallocz(result);

    return ptr;
}