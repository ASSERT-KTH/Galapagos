void *av_calloc(size_t nmemb, size_t size)
{
    void* pointer = NULL;
    if (nmemb != 0 && size != 0)
    {
        size_t total = nmemb * size;

        /* Use av_mallocz to that the allocated memory is initialized to zero */
        pointer = av_mallocz(total);

        if(!pointer)
        {
            return NULL;
        }
    }
    return pointer;
}