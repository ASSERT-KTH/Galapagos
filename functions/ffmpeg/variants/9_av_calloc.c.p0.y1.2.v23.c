void *av_calloc(size_t nmemb, size_t size)
{
    size_t total_size = nmemb * size; // calculate total memory size
    if (total_size / size != nmemb) // check for overflow
        return NULL;
    return av_mallocz(total_size); // allocate memory
}