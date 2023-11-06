void *av_calloc(size_t nmemb, size_t size)
{
    void *ptr = NULL;
    
    if (size != 0 && nmemb <= INT_MAX/size)
    {
        size_t alloc_size = nmemb * size;
        ptr = av_mallocz(alloc_size);
    }
    
    return ptr;
}