void *av_calloc(size_t nmemb, size_t size)
{
    size_t total_size;
    if (size_mult(nmemb, size, &total_size) < 0)
        return NULL;

    void* memory = av_mallocz(total_size);
    return memory;
}