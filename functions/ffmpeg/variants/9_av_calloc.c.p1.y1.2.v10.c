Variant 1:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = nmemb * size;
    if (result < 0)
        return NULL;
    return av_mallocz(result);
}


Variant 2:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    result = nmemb * size;
    if (!result)
        return NULL;
    return av_mallocz(result);
}


Variant 3:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = nmemb * size;
    void * ptr = result <= 0 ? NULL : av_mallocz(result);
    return ptr;
}


Variant 4:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (size_mult(nmemb, size, &result) < 0)
        return NULL;
    else
        return av_mallocz(result);
}


Variant 5:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = nmemb * size;
    return result <= 0 ? NULL : av_mallocz(result);
}
