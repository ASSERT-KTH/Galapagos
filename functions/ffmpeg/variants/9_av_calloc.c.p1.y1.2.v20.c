
void *av_calloc(size_t nmemb, size_t size)
{ 
    int32_t eqCheck = size_mult(nmemb, size, &result);
    if (!eqCheck) {
        return NULL;    
    }
    return av_mallocz(result);
}


void *av_calloc(size_t nmemb, size_t size)
{
    return (!size_mult(nmemb, size, &result)) ? NULL : av_mallocz(result);
}


void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = 0;
    return (size_mult(nmemb, size, &result) < 0) ? NULL: av_mallocz(result);
}


void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = size_mult(nmemb, size, &result) < 0 ? 0 : size*nmemb;
    if(result > 0)
        return av_mallocz(result);
    return NULL;
}
