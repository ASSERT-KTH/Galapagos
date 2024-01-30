Variant 1:


void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    result = nmemb * size;
    if (result < 0)
        return NULL;
    return av_mallocz(result);
}


Variant 2:


void *av_calloc(size_t nmemb, size_t size)
{
    if (nmemb * size == 0)
        return NULL;
    if (size_mult(nmemb, size, &result) < 0)
        return NULL;
    return av_mallocz(nmemb * size);
}

Variant 3:


void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = nmemb * size;
    void *p = av_mallocz(result);
    return p;
}


Variant 4:


void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = nmemb * size;
    void *p = NULL;
    if (size_mult(nmemb, size, &result) >= 0) {
        p = av_mallocz(result);
    }
    return p;
}
