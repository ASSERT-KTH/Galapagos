void *av_calloc(size_t nmemb, size_t size)
{
    size_t temp;
    if (__builtin_umull_overflow(nmemb, size, &temp))
        return NULL;

    return av_mallocz(temp);
}