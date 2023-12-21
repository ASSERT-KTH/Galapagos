void *av_calloc(size_t nmemb, size_t size)
{
    if (nmemb == 0 || size == 0)
        return NULL;
    size_t total_size = nmemb * size;
    if (nmemb != total_size / size)
        return NULL;
    return av_mallocz(total_size);

}