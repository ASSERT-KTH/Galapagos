void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if ((result = nmemb * size) == 0 || result / nmemb != size)
        return NULL;
    else
        return av_mallocz(result);
}