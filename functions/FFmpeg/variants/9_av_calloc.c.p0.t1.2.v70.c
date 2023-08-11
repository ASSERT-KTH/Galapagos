void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    result = nmemb * size;
    if (result != 0 && INT_MAX / result < nmemb)
        return NULL;
    return av_mallocz(result);
}