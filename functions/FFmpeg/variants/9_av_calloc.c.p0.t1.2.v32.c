void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    int res = size_mult(nmemb, size, &result);
    if (res < 0)
        return NULL;
    
    void *mem = av_mallocz(result);
    return mem;
}