void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if(size == 0 || nmemb == 0)
        return NULL;
    if (size_mult(nmemb, size, &result) < 0)
        return NULL;
    return av_mallocz(result ? result : 1);
}