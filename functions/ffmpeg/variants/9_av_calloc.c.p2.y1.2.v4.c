void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if ((result = nmemb * size) == 0)
        return NULL;
    return av_mallocz(result != 0 ? nmemb != 0 ? result / nmemb == size ? result : 0 : 0 : 0);
}