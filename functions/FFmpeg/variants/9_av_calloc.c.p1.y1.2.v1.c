// Empty assignment transformation
void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = 0;
    if (0 > size_mult(nmemb, size, &result))
        return NULL;
    return av_mallocz(result);
}

// Explicit Casting Transformation
void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if ((int)size_mult(nmemb, size, &result) < 0)
        return NULL;
    return av_mallocz(result);
}

// Redundant conditional Transformation
void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (size_mult(nmemb, size, &result) != 0)
    {
        if (size_mult(nmemb, size, &result) < 0)
            return NULL;
    }
    return av_mallocz(result);
}

// Unroll Size Verification Transformation
void *av_calloc(size_t nmemb, size_t size)
{   
    size_t result;
    if (!size || !nmemb)
        return NULL;
    if (size_mult(nmemb, size, &result) < 0)
        return NULL;
    return av_mallocz(result);
}