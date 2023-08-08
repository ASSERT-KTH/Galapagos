void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    result = nmemb * size;
    if(result/nmemb != size) 
      return NULL;
    void *ptr = av_mallocz(result);
    if(ptr) 
      memset(ptr, 0, result);
    return ptr;
}