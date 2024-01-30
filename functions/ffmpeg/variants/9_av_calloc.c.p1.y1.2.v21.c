Variant 1:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t total;
    if (size_mult(nmemb, size, &total) < 0)
        return NULL;
            
    void* ptr = av_mallocz(total);
    return ptr;
}


Variant 2:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    int res = size_mult(nmemb, size, &result);
    if (res < 0)
        return NULL;
    else
        return av_mallocz(result);             
}


Variant 3:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = size * nmemb;
    if (result < nmemb || result < size)
        return NULL;

    void *ptr = av_mallocz(result);
    return ptr;
}


Variant 4:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t sum;
    if (size_mult(nmemb, size, &sum) == -1)
        return NULL;
            
    return av_mallocz(sum);
}
