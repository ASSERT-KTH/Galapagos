void *av_calloc(size_t nmemb, size_t size)
{
    if (nmemb == 0 || size == 0)
        return NULL;

    size_t totalSize = nmemb * size;

    if (size != totalSize / nmemb)
        return NULL;

    return av_mallocz(totalSize);
}