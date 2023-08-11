void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    void* ptr = NULL;

    if(!(size_mult(nmemb, size, &result) < 0))
        ptr = av_mallocz(result);

    return ptr;
}