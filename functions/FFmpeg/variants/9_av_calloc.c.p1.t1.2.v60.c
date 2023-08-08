void *av_calloc(size_t nmemb, size_t size)
{
    if (!nmemb || !size)
        return NULL;

    size_t result = nmemb * size;

    // Check if multiplication operation overflowed.
    if(nmemb != 0 && result / nmemb != size)
        return NULL;

    // Result needs to be zeroed which is handled by av_mallocz.
    return av_mallocz(result);
}