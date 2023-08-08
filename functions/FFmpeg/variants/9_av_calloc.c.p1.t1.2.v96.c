void *av_calloc(size_t nmemb, size_t size)
{
    if(nmemb == 0 || size == 0)
        return NULL;

    size_t result = nmemb * size;
    
    // checking for integer overflow
    if(nmemb != 0 && result / nmemb != size)
        return(NULL);

    return av_mallocz(result);
}