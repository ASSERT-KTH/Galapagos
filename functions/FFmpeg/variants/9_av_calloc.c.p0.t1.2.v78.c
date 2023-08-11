void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    size_t total = nmemb * size;
    if (total == 0) 
        return NULL;
    result = total; 
    return av_mallocz(result);
}