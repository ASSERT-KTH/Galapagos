void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = nmemb * size;
    if (result/nmemb != size)
        return NULL;
    void *allocated_mem = av_mallocz(result);
    if(!allocated_mem)
        return NULL;
     return allocated_mem;
}