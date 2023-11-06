void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = nmemb * size;
    if (result < 0)
        return NULL;
    void* pointer = av_mallocz(result);
    if(pointer != NULL)
         memset(pointer, 0, result);
    return pointer;
}