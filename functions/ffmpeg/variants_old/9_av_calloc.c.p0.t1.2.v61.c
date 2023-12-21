void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if(size==0 || nmemb==0) 
        return NULL;
        
    if (size_mult(nmemb, size, &result) < 0)
        return NULL;

    void* returnValue = av_mallocz(result);
    
    if(returnValue==NULL) 
        return NULL;
      
    return returnValue;
}