void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = nmemb * size;
    void *ptr = NULL;

    if (result != 0) {
        ptr = av_mallocz(result);
    } else {
        return NULL;
    }

    return ptr;
}