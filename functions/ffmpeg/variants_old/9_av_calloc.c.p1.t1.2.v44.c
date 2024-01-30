void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;

    if (nmemb == 0 || size == 0)
        return NULL;

    result = nmemb * size;
    
    /* Check for overflow */
    if(nmemb != 0 && result / nmemb != size)
        return NULL;
    
    return av_mallocz(result);
}