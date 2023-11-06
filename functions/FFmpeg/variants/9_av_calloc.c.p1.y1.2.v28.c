Variant 1:


void *av_calloc(size_t nmemb, size_t size)
{
    void *mem;
    if (size_mult(nmemb, size, (size_t*)&mem) < 0)
        return NULL;
    return av_mallocz((size_t)mem);
}


Variant 2:


void *av_calloc(size_t nmemb, size_t size)
{
    if (size == 0 || nmemb == 0)
        return NULL;
    size_t memSize;
    if (size_mult(nmemb, size, &memSize) < 0)
        return NULL;
    return av_mallocz(memSize);
}



Variant 3:


void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = nmemb * size;
    if (result/nmemb != size)
        return NULL;
    return av_mallocz(result);
}


Variant 4:


void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (!(size && nmemb))
        return NULL;
    if (size_mult(nmemb, size, &result) < 0)
        return NULL;
    return av_mallocz(result);
}

Variant 5:


void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (!nmemb || !size || size_mult(nmemb, size, &result) < 0)
        return NULL;
    return av_mallocz(result);
}
