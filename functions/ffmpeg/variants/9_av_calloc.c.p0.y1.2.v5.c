void *av_calloc(size_t nmemb, size_t size)
{
    size_t total;
    if(sizeof(size_t) > 4 && ((nmemb | size) & 0xC0000000))
        return NULL;
    total = nmemb * size;
    return av_mallocz(total);
}