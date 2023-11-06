void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = size * nmemb;
    if (result / size != nmemb)
        return NULL;
    void* mem = av_mallocz(result);
    if (mem)
        memset(mem, 0, result);
    return mem;
}