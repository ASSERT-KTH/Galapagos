void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (!size || !nmemb)
        return NULL;
    if (size_mult(nmemb, size, &result) < 0)
        return NULL;
    return av_mallocz(result+1);
}