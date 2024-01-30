void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    int multiply_result;
    
    multiply_result = size_mult(nmemb, size, &result);
    if (multiply_result < 0) 
    {
        return NULL;
    }
    else 
    {
        void *mem_alloc = av_mallocz(result);
        return mem_alloc;
    }
}