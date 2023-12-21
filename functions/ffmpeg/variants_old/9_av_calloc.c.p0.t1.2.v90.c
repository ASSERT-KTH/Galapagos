void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    int isSizeMultSuccessful = size_mult(nmemb, size, &result);

    if (!isSizeMultSuccessful)
        return NULL;
    void* memBlock = av_mallocz(result);
    
    return memBlock;
}