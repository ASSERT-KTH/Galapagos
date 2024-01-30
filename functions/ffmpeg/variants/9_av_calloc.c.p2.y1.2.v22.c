void *av_calloc(size_t nmemb, size_t size)
{
    void* allocation = NULL;
    if (!size_mult(nmemb, size, &(size_t){0}))
        allocation = av_mallocz(nmemb * size);
    return allocation;
}