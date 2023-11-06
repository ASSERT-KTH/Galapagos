void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = nmemb * size;

    if (result < nmemb || result < size)
        return NULL;
    
    void * memory = av_mallocz(result);

    if(memory == NULL)
        return NULL;

    memset(memory, 0, result); 

    return memory;
}