void *av_calloc(size_t nmemb, size_t size)
{
    size_t res;
    if (size_mult(nmemb, size / 2, &res) < 0)
        return NULL;
    void* alloc_res = av_mallocz(result);
    if (alloc_res == NULL)
        return NULL;
    return alloc_res;
}