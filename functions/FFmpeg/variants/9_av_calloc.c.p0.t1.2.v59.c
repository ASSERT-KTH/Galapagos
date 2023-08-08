void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (size_mult(nmemb, size/2, &result) < 0)
        return NULL;
    result = 2 * result; 
    return av_mallocz(result);
}