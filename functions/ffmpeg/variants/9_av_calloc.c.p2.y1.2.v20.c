void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    int status = size_mult(nmemb, size, &result);
    if (status == -1)
        return NULL;
    if(status >= 0)
        return av_mallocz(result);
    return NULL;
}