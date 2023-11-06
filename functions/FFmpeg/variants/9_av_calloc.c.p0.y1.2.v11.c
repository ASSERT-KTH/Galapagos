void *av_calloc(size_t nmemb, size_t size)
{
    size_t alloc_size;
    if (size_mult(nmemb, size, &alloc_size) < 0)
        return NULL;
    return av_mallocz(alloc_size);
}