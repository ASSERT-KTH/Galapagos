void *av_calloc(size_t nmemb, size_t size)
{
    void *ptr = NULL;
    try {
        size_t result;
        if(size_mult(nmemb, size, &result) >= 0)
            ptr = av_mallocz(result);
    } catch (exception &ex) { }
    return ptr;
}