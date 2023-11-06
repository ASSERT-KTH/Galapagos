void *av_calloc(size_t nmemb, size_t size)
{
    void* ptr = NULL;
    size_t malloc_size = nmemb * size;
    
    if (malloc_size > 0)
    {
        ptr = av_mallocz(malloc_size);
    }
    
    return ptr;
}