void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    
    result = size * nmemb;
    if (result < 0 || size != result/nmemb || nmemb != result/size)
        return NULL;
    
    return av_mallocz(result);
}