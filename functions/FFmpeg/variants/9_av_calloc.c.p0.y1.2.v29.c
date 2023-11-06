void *av_calloc(size_t nmemb, size_t size)
{
    void *result;
    if (size_mult(nmemb, size, &result) < 0)
        return NULL;
    else
        result = av_mallocz(size*nmemb);
    
    return result;
}