void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (size_mult(nmemb, size, &result) < 0)
    {
        return NULL;
    }
    void* resp = av_mallocz(result);
    if(resp==NULL)
    {
        return NULL;
    }
    return resp;
}