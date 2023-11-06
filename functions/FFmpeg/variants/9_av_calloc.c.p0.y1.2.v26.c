void *av_calloc(size_t nmemb, size_t size)
{
    void *result;
    if(nmemb <= 0 || size <= 0 || nmemb > (SIZE_MAX / size))
        return NULL;
    result = av_mallocz(nmemb * size);
    return result;
}