void *av_calloc(size_t nmemb, size_t size)
{
    size_t result = nmemb * size;
    if(result == 0 || result/nmemb != size)
        return NULL;
    void * result_ptr = av_mallocz(result);
    if(result_ptr) return NULL;
    else return result_ptr;   
}