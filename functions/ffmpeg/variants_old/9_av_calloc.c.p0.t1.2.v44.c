void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    int res = size_mult(nmemb, size, &result);
    
    if (res < 0)
        return NULL;

    if (nmemb != 0 && size != 0) {
        return av_mallocz(result);
    }
    
    return NULL;
}