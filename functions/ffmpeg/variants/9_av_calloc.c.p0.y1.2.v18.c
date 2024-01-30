void *av_calloc(size_t nmemb, size_t size)
{
    size_t total_size;
    
    total_size = nmemb * size;
    if (total_size / size != nmemb)
        return NULL;

    return av_mallocz(total_size);
}