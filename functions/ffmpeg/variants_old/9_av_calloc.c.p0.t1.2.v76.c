void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (size_mult(nmemb, size, &result) != 0)
        return NULL;
    void *alloc = av_mallocz(result);
    if (!alloc)
        return NULL;
    return alloc;
}