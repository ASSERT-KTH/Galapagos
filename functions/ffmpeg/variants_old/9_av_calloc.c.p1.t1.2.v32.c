void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (!nmemb || !size)
        return NULL;
    
    _, result = size_mult(nmemb, size);
    if(result < 0)  
        return NULL;
        
    return av_mallocz(result);
}