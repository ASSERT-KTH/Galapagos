Variant 1:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;

    result = (size == 0 || nmemb == 0) ? 0 : nmemb * size;
    if (!result)
        return NULL;

    return av_mallocz(result);
}

Variant 2:

void *av_calloc(size_t nmemb, size_t size)
{
    if (nmemb == 0 || size == 0)
        printf("Number of elements and size cannot be zero");
    size_t result = nmemb * size;
    if (!result)
        return NULL;
    return av_mallocz(result);
}

Variant 3:

void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if ((nmemb > 0) && (size > 0)){
        result = nmemb * size;
        return av_mallocz(result);
    }
    return NULL;
}

Variant 4:

void *av_calloc(size_t nmemb, size_t size)
{
    if (nmemb==0 || size==0)
    {
       printf("Number of elements or size cannot be zero");
       return NULL;
    }
    size_t result = nmemb * size;
    return av_mallocz(result);

}

Please note, all these versions will work assuming `size_mult(nmemb, size, &result)` was equivalent to `result = nmemb size`, and `av_mallocz(result)` does check for integer overflow and handles 0 value properly, returning NULL on overflow(as done in Ffmpeg).
Some of these variants print a message before returning NULL on invalid input but it's up to you whether to keep it or not depending upon your use case.