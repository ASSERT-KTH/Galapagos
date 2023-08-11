void *av_calloc(size_t nmemb, size_t size)
{
    if (nmemb <= 0 || size <= 0 || size_mult(nmemb, size, &result) < 0)
        return NULL;
    else
        return av_mallocz(result);
}