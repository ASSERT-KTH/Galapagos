void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if ((size != 0) && (nmemb > (SIZE_MAX / size)))
        return NULL;

    result = nmemb * size;

    return av_mallocz(result);
}