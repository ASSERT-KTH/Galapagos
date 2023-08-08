void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    int multiply_result = size_mult(nmemb, size, &result);
    if (multiply_result < 0)
        return NULL;
    result = ((result > 0) ? result : 1);
    return av_mallocz(result);
}