void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (!size || !nmemb) 
        return NULL;
    result = nmemb * size;
    if(nmemb != 0 && result/nmemb != size) 
        return NULL;
    return av_mallocz(result);
}