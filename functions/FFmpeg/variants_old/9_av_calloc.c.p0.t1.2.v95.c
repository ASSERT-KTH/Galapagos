void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (size >= (SIZE_MAX / nmemb))
        return NULL;             
    result = nmemb * size;
    return av_mallocz(result);
}