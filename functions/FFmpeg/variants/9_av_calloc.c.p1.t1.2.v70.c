void *av_calloc(size_t nmemb, size_t size)
{
    void* result;
    size_t totalSize = nmemb * size;

    if(totalSize <= 0)
        return NULL;

    result = av_mallocz(totalSize);

    if(!result)
        return NULL;

    return result;
}