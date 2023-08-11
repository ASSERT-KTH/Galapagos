void *av_calloc(size_t nmemb, size_t size)
{
    if (size == 0 || nmemb == 0) return NULL;
    
    size_t result;
    
    if(size_mult(nmemb, size, &result) < 0) return NULL;
    
    void* pointer = av_mallocz(result);
    
    if (pointer == NULL)        
        return NULL;
    
    else
        return pointer;
}