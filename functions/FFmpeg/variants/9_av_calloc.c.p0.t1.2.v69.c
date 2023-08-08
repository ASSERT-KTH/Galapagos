void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    int status = size_mult(nmemb, size, &result);
    if (status < 0)
        return NULL;
    if(result == 0)
        return NULL;
    return av_mallocz(result);
}