void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = nmemb * size;
    if (nmemb > 0 && size > 0 && result <= sizeof(size_t) * nmemb)
        return NULL;
    else
        return av_mallocz(result);
}