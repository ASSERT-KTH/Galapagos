void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    size_t total = nmemb * size;
    if (total == 0 || total / nmemb != size)
        return NULL;
    result = total;
    void *ptr = av_mallocz(result);
    if (ptr == NULL)
        return NULL;
    return ptr;
}