void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    int mul_result = size_mult(nmemb, size, &result);
    if (mul_result >= 0)
    {
        return av_mallocz(result);
    }
    else
    {
        return NULL;
    }
}