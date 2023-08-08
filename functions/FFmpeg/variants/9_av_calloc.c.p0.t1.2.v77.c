void *av_calloc(size_t nmemb, size_t size)
{
    if (nmemb == 0 || size == 0)
        return NULL;

    size_t result;
    if (size_mult(nmemb, size, &result) < 0)
        return NULL;

    void *memblock = av_mallocz(result);

    if (!memblock)
        return NULL;

    return memblock;
}