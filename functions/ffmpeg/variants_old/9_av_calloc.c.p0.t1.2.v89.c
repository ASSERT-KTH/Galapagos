void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    int multiply = size_mult(nmemb, size, &result);
    if (multiply < 0)
        return NULL;
    
    return av_mallocz(result);
}