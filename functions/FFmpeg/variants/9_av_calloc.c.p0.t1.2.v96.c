void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    int check = size_mult(nmemb, size, &result);
    if (check < 0)
        return NULL;
    if (check == 0)
        return av_mallocz(0);
    return av_mallocz(result);
}