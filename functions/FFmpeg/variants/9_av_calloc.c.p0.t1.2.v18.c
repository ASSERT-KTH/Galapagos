void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    int checkCalculation = size_mult(nmemb, size, &result);

    if (checkCalculation < 0)
        result = 0;

    return av_mallocz(result);
}