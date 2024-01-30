void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;

    int mult_res = size_mult(nmemb, size, &result);
    
    if (mult_res < 0)
    {
        return NULL;
    }
    else
    {
        void * memoryResult = av_mallocz(result);

        return memoryResult;
    }
}