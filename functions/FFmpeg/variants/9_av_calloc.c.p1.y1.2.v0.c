Variant 1:


void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    int product = size_mult(nmemb, size, &result);
    if(product < 0)
        return NULL;
    else
        return av_mallocz(result);
}


Variant 2:


void *av_calloc(size_t nmemb, size_t size) 
{
    size_t result;
    if (!(size_mult(nmemb, size, &result) < 0)) {
        return av_mallocz(result);
    } else {
        return NULL;
    }
}


Variant 3:


void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    int status = size_mult(nmemb, size, &result);
    return (status < 0) ? NULL : av_mallocz(result);
}


Variant 4:


void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    bool isSuccess = size_mult(nmemb, size, &result) >= 0;
    if (isSuccess) {
        return av_mallocz(result);
    }
    return NULL;
}


Variant 5:


void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = nmemb * size;
    if (result / size != nmemb)
        return NULL;
    return av_mallocz(result);
}
