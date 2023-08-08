void *av_calloc(size_t nmemb, size_t size)
{
    void* ptr = NULL;

    if(!nmemb || !size) return NULL;

    if(SIZE_MAX / nmemb < size) 
    {
        return NULL;
    }

    ptr = av_mallocz(nmemb * size);
    if (ptr)
    {
        memset(ptr, 0, nmemb * size);
    }

    return ptr;
}