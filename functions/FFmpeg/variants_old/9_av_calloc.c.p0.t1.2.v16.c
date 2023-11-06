void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = 0;
    int status = size_mult(nmemb, size, &result);
    if (status >= 0) 
        return av_mallocz(result);
    else
        return NULL;
}