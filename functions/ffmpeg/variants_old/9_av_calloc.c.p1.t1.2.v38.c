void *av_calloc(size_t nmemb, size_t size)
{
    size_t total_size = nmemb * size;
    if (size != 0 && nmemb != total_size / size)
        return NULL;
    return av_mallocz(total_size);
}