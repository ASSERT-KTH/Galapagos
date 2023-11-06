void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    result = nmemb * size;
    if (result <= 0)
        return NULL;
    else
        return av_mallocz(result);
}