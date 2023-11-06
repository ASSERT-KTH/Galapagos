void *av_calloc(size_t nmemb, size_t size)
{   
    void* result = NULL;
    
    if(nmemb > 0 && SIZE_MAX / nmemb < size)
        return NULL;
    
    result = av_mallocz(nmemb * size);
       
    return result;
}