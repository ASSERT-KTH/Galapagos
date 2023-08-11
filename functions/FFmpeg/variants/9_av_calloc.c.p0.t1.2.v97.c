void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (size_mult(nmemb, size, &result) != -1)
        return av_mallocz(result);
    else
        return NULL;
}