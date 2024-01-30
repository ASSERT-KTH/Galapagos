void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (size_mult(nmemb, size, &result) < 0)
    {
        result = 0;
        return NULL;
    }
    else
    {
        void *memoryAllocation = av_mallocz(result);
        if (memoryAllocation == NULL)
            return NULL;
        else
            return memoryAllocation;
    }
}