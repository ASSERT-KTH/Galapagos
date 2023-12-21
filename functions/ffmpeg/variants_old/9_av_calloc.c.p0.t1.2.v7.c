void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (size_mult(nmemb, size, &result) != 0)
        return NULL;
    void* new_memory = av_mallocz(result);
    if (new_memory == NULL)
        return NULL;
    return new_memory;
}