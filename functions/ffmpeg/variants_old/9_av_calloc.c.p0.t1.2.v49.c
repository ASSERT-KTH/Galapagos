void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (size_mult(nmemb, size, &result) < 0){
        result = 0;
    }
    void* mem = av_mallocz(result);
	
    if (mem)
        memset(mem, 0, result); 

    return mem;     
}