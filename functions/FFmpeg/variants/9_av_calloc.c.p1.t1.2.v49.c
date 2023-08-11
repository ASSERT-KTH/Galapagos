void *av_calloc(size_t nmemb, size_t size)
{
    if (!nmemb || !size)
        return NULL;
        
    size_t result = nmemb * size;
    
    if (result / nmemb != size)
        return NULL;
        
    return av_mallocz(result);
}