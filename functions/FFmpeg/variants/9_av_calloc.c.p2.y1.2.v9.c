void *av_calloc(size_t nmemb, size_t size)
{
    void *pointer = NULL;
    size_t result;

    if (size_mult(nmemb, size, &result) >= 0)
        pointer = av_mallocz(result);
        
    return pointer;
}