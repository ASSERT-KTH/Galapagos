Variant 1:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (size_mult(nmemb, size, &result) < 0)
        return NULL;
    void *ptr = av_mallocz(result);
    return ptr;
}


Variant 2:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (size_mult(nmemb, size, &result) >= 0)
    {
        return av_mallocz(result);
    }
    return NULL;
}


Variant 3:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    int status = size_mult(nmemb, size, &result);
    if (status < 0) 
    {
        return NULL;
    }
    else 
    {
        return av_mallocz(result);
    }
}


Variant 4:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    result = nmemb * size;
    if(result != nmemb || result != size)
        return NULL;
    else 
        return av_mallocz(result);
}


Variant 5:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = nmemb * size;
    if(result==0)
        return NULL;
    else 
        return av_mallocz(result);
}


-Make sure you're using these transformations considerately to your system behaviour once the operations may not have the same expected result in different ways your system handle exceptions or overflows.