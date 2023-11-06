void *av_calloc(size_t nmemb, size_t size)
{
    size_t totalSize = nmemb * size;

    if (totalSize / nmemb != size)
        return NULL;
        
    return av_mallocz(totalSize);
}