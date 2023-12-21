void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    int check_result = size_mult(nmemb, size, &result);
    if (check_result < 0)
        return NULL;
    void *pointer = av_mallocz(result);
    return pointer;
}