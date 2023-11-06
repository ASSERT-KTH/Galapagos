void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (!(nmemb != 0 && size != 0 && nmemb*size == result))
        return NULL;
    void *ptr = av_mallocz(result);
    return ptr;
}