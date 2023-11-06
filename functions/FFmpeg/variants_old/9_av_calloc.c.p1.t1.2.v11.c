void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;

    // Check if there is an overflow in multiplication of size by nmemb.
    result = nmemb * size;
    if ((result != 0 && (size == 0 || nmemb == 0)) ||
        (result / size != nmemb) ||
        (result / nmemb != size))
    {
        return NULL;
    }
    return av_mallocz(result);
}