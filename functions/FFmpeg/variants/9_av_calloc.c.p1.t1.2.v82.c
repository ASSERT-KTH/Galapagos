void *av_calloc(size_t nmemb, size_t size)
{
    if (nmemb == 0 || size == 0) return NULL;

    size_t required_mem = nmemb * size;

    if (nmemb != required_mem / size)
        return NULL; 

    void* allocated_mem = av_mallocz(required_mem);

    if(allocated_mem == NULL)
        return NULL;

    return allocated_mem;
}