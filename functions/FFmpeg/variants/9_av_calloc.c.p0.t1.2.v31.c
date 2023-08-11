void* av_calloc(size_t nmemb, size_t size)
{
    if(nmemb == 0 || size == 0)   // if either is zero, skip computation and return immediately
        return NULL;
        
    size_t result;
    if (size_mult(nmemb, size, &result) < 0)
        return NULL;
     
     void *p = av_mallocz(result);
     
     if (!p)   // additional check to avoid potential issues after mallocz
         return NULL;
         
     return p;
}