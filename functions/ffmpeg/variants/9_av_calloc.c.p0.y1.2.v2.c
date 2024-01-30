void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = nmemb * size;
    if (result < 0)
        return NULL;
    
    void* data = av_mallocz(result);
    if(data == NULL)
        return NULL;

    return data;
}