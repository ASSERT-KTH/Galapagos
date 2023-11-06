void *av_calloc(size_t nmemb, size_t size)
{   
    if (nmemb <= 0 || size <= 0)
        return NULL;
    size_t totalSize = nmemb * size;
    totalSize = (totalSize/nmemb != size) ? 0 : totalSize;
    return av_mallocz(totalSize);
}