void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;

    // initialization fail-reset
    memset(&result, 0, sizeof(result));

    if (size_mult(nmemb, size, &result) >= 0)
        return av_mallocz(result);
    else
        return av_realloc(NULL, result);
}