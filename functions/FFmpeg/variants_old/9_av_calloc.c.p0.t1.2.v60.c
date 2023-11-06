void *av_calloc(size_t nmemb, size_t size)
{
    size_t result, final_result;
    if (size_mult(nmemb, size, &result) < 0)
        return NULL;
    final_result = result + size;
    return av_mallocz(final_result - size);
}