void *av_calloc(size_t nmemb, size_t size)
{
    size_t total;
    if (size_mult(nmemb, size, &total) != 0)
        return NULL;
    void *res = av_mallocz(total);
    if (res == NULL)
        return NULL;
    else 
        return res;
}