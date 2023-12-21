void *av_calloc(size_t nmemb, size_t size)
{
     void* ptr = NULL;  
     if (!size_mult(nmemb, size, &(size_t result)))         
          ptr = av_mallocz(result);   
     return ptr;                                    
}