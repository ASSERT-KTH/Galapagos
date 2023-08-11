void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;

    if (nmemb<0 || size<0)
        return NULL;
      
    result = nmemb * size;

    if(size != 0 && result/size != nmemb){
        return NULL;
    }

    void *ptr = av_mallocz(result);
      
    if (ptr)
        memset(ptr, 0, result);

    return ptr;
}