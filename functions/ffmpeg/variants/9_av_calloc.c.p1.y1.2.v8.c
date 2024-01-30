Variant 1:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if ((result = nmemb * size) < 0)
        return NULL;
    return av_mallocz(result);
}

Variant 2:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = size * nmemb;
    if (result < 0)
        return NULL;
    return av_mallocz(result);
}

Variant 3:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = nmemb * size;
    if (result < 0) 
        return NULL;
    else 
        return av_mallocz(result);
}

Variant 4:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    bool isNegative = ((result = nmemb * size) < 0);
    return isNegative ? NULL : av_mallocz(result);
}
">
