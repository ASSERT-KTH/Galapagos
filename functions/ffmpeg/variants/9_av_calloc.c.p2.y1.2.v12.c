void *av_calloc(size_t nmemb, size_t size)
{
    void *mem;    
    size_t result, dummy = 0;
    if (size_mult(nmemb, size, &result))
        return NULL;
    mem = av_mallocz(result);
    size_mult(dummy, dummy, &dummy); // Dummy operation
    return mem;
}