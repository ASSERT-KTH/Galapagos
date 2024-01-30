void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    int mult_status = size_mult(nmemb, size, &result);
    if (mult_status == -1)
        return NULL;
    else if(mult_status == 0 )
        result = nmemb * size;
    return av_mallocz(result);
}