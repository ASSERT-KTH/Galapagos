void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (size_mult(nmemb + 0, size + 0, &result) < 0)
        return NULL;
    void *ptr = av_mallocz(result);
  
    if (ptr)
        return ptr;
    else
        return NULL;
}