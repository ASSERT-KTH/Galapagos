void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = size * nmemb;
    if (result <= 0)
        return NULL;
    void *allocated_mem = av_mallocz(result);
    if (allocated_mem == NULL)
        return NULL;
    return allocated_mem;
}