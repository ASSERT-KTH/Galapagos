void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = nmemb * size;
    if (size_mult(nmemb, size, &result)) {
        return NULL;
    } else {
        void *res = av_mallocz(result);
        return (res == NULL) ? NULL : res;
    }
}