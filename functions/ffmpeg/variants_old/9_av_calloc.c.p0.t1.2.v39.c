void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;

    if(nmemb == 0 || size == 0)
        return NULL;
  
    if ((UINT_MAX / nmemb) < size)
        return NULL;
    
    result = nmemb * size;
    return av_mallocz(result);
}