void *av_calloc(size_t nmemb, size_t size)
{
    void *ptr;
    if (size == 0 || nmemb == 0)
       return NULL;
    ptr = av_mallocz(nmemb * size);
    if(ptr) {
       memset(ptr, 0, nmemb * size);
    }
    return ptr;
}