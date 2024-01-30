void *av_calloc(size_t nmemb, size_t size)
{
    void *ptr = NULL;
    if (!size_mult(nmemb, size, &size))
    {
        ptr = av_mallocz(size);
    }
    return ptr;
}