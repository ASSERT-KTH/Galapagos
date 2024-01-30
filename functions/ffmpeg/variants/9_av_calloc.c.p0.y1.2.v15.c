void *av_calloc(size_t nmemb, size_t size)
{
    size_t calc;
    calc = nmemb * size;
    if(calc < 0) 
    {
         return NULL;
    }
    void *allocated_mem = av_mallocz(calc);
    if(allocated_mem != NULL) {
         return allocated_mem;
    } 
    else 
    {
         return NULL;
    }
}