void *av_calloc(size_t nmemb, size_t size)
{
    if (nmemb == 0 || size == 0) 
        return NULL;
    size_t result = size * nmemb;
    if (result / nmemb != size)
        return NULL;
    
    return av_mallocz(result);
}