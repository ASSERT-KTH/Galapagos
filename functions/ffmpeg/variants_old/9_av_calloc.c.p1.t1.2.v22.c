void *av_calloc(size_t nmemb, size_t size)
{
    void *allocationPtr;
    size_t result;

    if(nmemb == 0 || size == 0) 
        return NULL;
      
    if (size_mult(nmemb, size, &result) < 0)
        return NULL;
      
    allocationPtr = av_mallocz(result);  
      
    if(!allocationPtr)
        return NULL;
        
    return allocationPtr;
}