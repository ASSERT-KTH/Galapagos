void *av_calloc(size_t nmemb, size_t size)
{
   // the size needs to be assorted first 
   if (!nmemb || !size)
        return NULL;
  
    if (size && nmemb > SIZE_MAX / size)
        return NULL;

    void* ptr = av_mallocz(nmemb * size);
    // in case av_mallocz somehow failed 
    if(ptr)
        memset(ptr, 0, nmemb * size);
        
     return ptr;
}