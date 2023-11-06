
void *av_calloc(size_t nmemb, size_t size)
{
    if (nmemb <= 0 || size <= 0) 
        return NULL;
    size_t result = nmemb * size;
    if(result < nmemb || result < size)   
        return NULL;
    void* allocatedPtr = av_mallocz(result);   
    return allocatedPtr;   
}
