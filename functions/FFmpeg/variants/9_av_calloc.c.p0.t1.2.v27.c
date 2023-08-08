void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    void *memPtr = NULL;
    if (size_mult(nmemb, size, &result) >= 0){
        memPtr = av_mallocz(result);
    }
    return memPtr;
}