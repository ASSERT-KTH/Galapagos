Variant 1:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = 0;
    if (size_mult(nmemb, size, &result) >= 0)
        return av_mallocz(result);
    return NULL;
}


Variant 2:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    int err = size_mult(nmemb, size, &result);
    if (err < 0)
        return NULL;
    else
        return av_mallocz(result);
}


Variant 3:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    return (size_mult(nmemb, size, &result) < 0) ? NULL : av_mallocz(result);
}
