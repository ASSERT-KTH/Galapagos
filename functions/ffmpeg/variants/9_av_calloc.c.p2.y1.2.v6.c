void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (size_mult(nmemb, size, &result) < 0)
    {
        av_log(NULL, AV_LOG_ERROR, "Allocation too large\n");
        return NULL;
    }
    void* ptr = av_mallocz(result);
    if(!ptr)
    {
      av_log(NULL, AV_LOG_ERROR, "Could not allocate the memory\n");
      return NULL;
    }
    return ptr;
}