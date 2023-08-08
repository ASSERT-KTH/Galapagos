void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = nmemb * size;
    
    if(result/nmemb != size) {
        return NULL;
    } 

    void* allocated_memory = av_mallocz(result);
    
    if(allocated_memory == NULL) {         
        return NULL;
    }

    return memset(allocated_memory, 0, result);
}