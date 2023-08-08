void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    int status;
    status = size_mult(nmemb, size, &result);
    if (status < 0)
        return NULL;

    void *mem = av_mallocz(result);
    return mem;
}