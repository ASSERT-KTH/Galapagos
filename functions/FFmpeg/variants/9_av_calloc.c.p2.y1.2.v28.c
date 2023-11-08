void *av_calloc(size_t nmemb, size_t size)
{
    void *ptr;
    size_t result;
    if (size_mult(nmemb, size, &result) < 0)
        ptr = NULL;
    else
        ptr = av_mallocz(result);
    
    return ptr;
}