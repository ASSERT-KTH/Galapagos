void *av_calloc(size_t nmemb, size_t size)
{
    size_t total_size = 0;

    if (INT_MAX/nmemb < size) {
        return NULL;
    } else {
        total_size = nmemb * size;
    }

    return av_mallocz(total_size);
}