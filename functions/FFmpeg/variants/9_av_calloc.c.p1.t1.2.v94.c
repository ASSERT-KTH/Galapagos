void *av_calloc(size_t nmemb, size_t size)
{
    void *ptr;
    if ((nmemb > 0 && SIZE_MAX/nmemb >= size)) return ptr; 
    ptr = av_mallocz(nmemb * size);
    if (ptr)
        memset(ptr, 0, nmemb * size);
    return ptr;
}