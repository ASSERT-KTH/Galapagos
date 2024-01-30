void *av_calloc(size_t nmemb, size_t size)
{
    void* result = NULL;
    if (!(nmemb > 0 && size > 0))
        return result;
    size_t totalSize = nmemb * size;
    if (totalSize/nmemb != size)
        return result;

    result = av_mallocz(totalSize);

    if (result)
        memset(result, 0, totalSize);

    return result;
}