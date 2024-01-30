void *av_calloc(size_t nmemb, size_t size)
{
    if(nmemb <= 0 || size <= 0) 
        return NULL;

    size_t result = nmemb * size;

    if(result != 0 && (result / nmemb != size))   
        return NULL;

    void* pointer = av_mallocz(result);
    if(pointer != NULL)  
        memset(pointer, 0x00, result); 

    return pointer; 
}