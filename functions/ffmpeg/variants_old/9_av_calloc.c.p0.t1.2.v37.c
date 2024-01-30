void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (size_mult(nmemb, size, &result) < 0)
    {
        return av_mallocz(0); 
    }
    else
    {
        return size ? av_mallocz(result) : NULL;
    }
}