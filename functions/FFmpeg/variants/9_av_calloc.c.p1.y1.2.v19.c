Variant 1:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    result = nmemb * size;
    if(result / nmemb != size)
        return NULL;
    return av_mallocz(result);
}


Variant 2:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = nmemb * size;
    if(result != nmemb && result / nmemb == size)
        return av_mallocz(result);
    else 
        return NULL;
}


Variant 3:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = size * nmemb;
    return (result / size == nmemb) ? av_mallocz(result) : NULL;
}
