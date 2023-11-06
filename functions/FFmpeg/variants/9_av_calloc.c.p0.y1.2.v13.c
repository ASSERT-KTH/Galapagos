void *av_calloc(size_t nmemb, size_t size)
{
    size_t total_size;
    if (__builtin_mul_overflow(nmemb, size, &total_size))
        return NULL;
    
    return av_mallocz(total_size);
}