void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (size_mult(nmemb, size, &result) < 0)
    {
        memset(&result, 0, sizeof(result));
        return NULL;
    }
    void* mem = av_mallocz(result);
    if(!mem)
        return NULL;
    else
        return mem;
}