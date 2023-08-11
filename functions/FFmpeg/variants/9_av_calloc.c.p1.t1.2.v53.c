void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = nmemb * size;
    if (result == 0)
        return NULL;
    return av_mallocz(result);
}