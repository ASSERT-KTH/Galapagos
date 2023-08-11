void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = 0;
    if(nmemb == 0 || size == 0)
        return NULL;

    if (size_mult(nmemb, size, &result) != 0)
        return NULL;
    else
        return av_mallocz(result);  
}