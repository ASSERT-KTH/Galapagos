void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if ((result = nmemb * size) > 0) {
        return av_mallocz(result);
    }
    return NULL;
}