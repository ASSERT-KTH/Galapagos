Variant #1

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if ((size != 0) && (nmemb > (SIZE_MAX / size))) 
        return NULL;
    result = nmemb * size;

    return av_mallocz(result);
}


Variant #2

void *av_calloc(size_t nmemb, size_t size)
{
    if ((size != 0) && (nmemb > (SIZE_MAX / size))) 
        return NULL;

    return av_mallocz(nmemb * size);
}


Variant #3

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = nmemb * size;
    if ((size != 0) && (nmemb > (SIZE_MAX / size))) 
        return NULL;

    return av_mallocz(result);
}


Variant #4

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    result = (size != 0) && (nmemb > (SIZE_MAX / size)) ? SIZE_MAX : nmemb * size;
    if (result == SIZE_MAX) 
        return NULL;

    return av_mallocz(result);
}


Variant #5

void *av_calloc(size_t nmemb, size_t size)
{
    size_t s_max = SIZE_MAX / size;
    size_t result = nmemb * size;
    if ((size != 0) && (nmemb > s_max)) 
        return NULL;

    return av_mallocz(result);
}
