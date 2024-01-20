void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (size_mult(nmemb, size, &result) < 0)
        return NULL;
    void *memory = av_mallocz(result);
    if (memory == NULL)
        return NULL;
    return memory;
}