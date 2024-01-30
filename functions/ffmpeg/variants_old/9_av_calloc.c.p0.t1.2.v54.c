void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (size_mult(nmemb, size, &result) >= 0)
    { 
        void* ptr = av_mallocz(result);
        if(ptr != NULL)  
           return ptr;
    }

    return NULL;
}