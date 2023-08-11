void *av_calloc(size_t nmemb, size_t size)
{
    void *output = NULL;
    
    size_t result;
    int checkResult = size_mult(nmemb, size, &result);
    if (checkResult >= 0)
        output = av_mallocz(result);

    return output;
}