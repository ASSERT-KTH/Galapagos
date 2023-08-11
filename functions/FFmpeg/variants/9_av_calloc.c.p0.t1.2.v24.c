void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;

    int multiplier = size_mult(nmemb, size, &result);
    
    if (multiplier >= 0)
    {
        return av_mallocz(result);
    }
    else
    {
        return NULL;
    }
}