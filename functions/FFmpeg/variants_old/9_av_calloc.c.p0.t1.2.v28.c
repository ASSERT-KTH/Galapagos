void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (size_mult(nmemb, size, &result) < 0)
        return NULL;
    else {
       void *av_val = av_mallocz(result);
       return av_val == NULL ? NULL : av_val;
    }
}