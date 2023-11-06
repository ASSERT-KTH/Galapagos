void *av_calloc(size_t nmemb, size_t size)
{
    size_t total_size;
    if((nmemb && size > SIZE_MAX / nmemb) || ((total_size = nmemb * size) && !av_mem))
        return NULL;
    return av_mallocz(total_size);
}