void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    int success = size_mult(nmemb, size, &result);
    if (success < 0)
        return NULL;
    void* memory = av_mallocz(result);
    if (memory == NULL) 
        return NULL;
    return memory;
}