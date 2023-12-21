void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    int errcode = size_mult(nmemb, size, &result);
    if (errcode == -errno)
        return NULL;
    size_t * allocated_memory = (size_t*) av_mallocz(result);
    if (allocated_memory == NULL)
        return NULL;
    return allocated_memory;
}