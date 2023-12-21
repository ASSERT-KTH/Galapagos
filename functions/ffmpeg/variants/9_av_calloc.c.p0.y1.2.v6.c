void *av_calloc(size_t nmemb, size_t size)
{
    size_t computed_size;
    if (!size || !nmemb || (computed_size = size * nmemb) / size != nmemb)
        return NULL;
    return av_mallocz(computed_size);
}