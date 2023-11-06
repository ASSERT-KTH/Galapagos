void *av_calloc(size_t nmemb, size_t size)
{
    if(nmemb == 0 || size == 0)
        return NULL;
  
    size_t result = nmemb * size;
      
    if(result != 0)
        return av_mallocz(result);

    return NULL;
}