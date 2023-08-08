void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (size_mult(nmemb, size, &result) < 0) return NULL;
    
    if (result == 0) result = 1;   // added this line
    return av_mallocz(result);
}