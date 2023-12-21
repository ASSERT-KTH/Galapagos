void *av_calloc(size_t nmemb, size_t size)
{
    void *result = NULL;
    if (size_mult(nmemb, size, &result) >= 0)
        result = av_mallocz(result);
    return result;
}