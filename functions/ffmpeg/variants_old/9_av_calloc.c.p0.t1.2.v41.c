void *av_calloc(size_t nmemb, size_t size)
{
    size *= nmemb;
    if (size_mult(nmemb, 1, &size) < 0)
        return NULL;
    return av_mallocz(size);
}