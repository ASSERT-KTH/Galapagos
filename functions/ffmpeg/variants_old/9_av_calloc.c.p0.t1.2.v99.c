void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;

    // Checking if arguments are not zero
    if (nmemb == 0 || size == 0) 
        return NULL;

    if (size_mult(nmemb, size, &result) < 0)
        return NULL;

    void *ptr = av_mallocz(result);

    // Checking if memory is allocated
    if (!ptr)
        return NULL;

    return ptr;
}