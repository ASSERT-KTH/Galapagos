void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (nmemb != 0 && size != 0)
    {
        result = nmemb * size;
        return av_mallocz(result);
    }
    else 
    {
        return NULL;
    }
}