void *av_calloc(size_t nmemb, size_t size) 
{
    size_t result;

    if (nmemb == 0 || size == 0)
        return NULL;

    result = nmemb * size;

    /* check for integer overflow */
    if (nmemb != 0 && result / nmemb != size)
        return NULL;

    /* av_mallocz() has the functionality of calloc itself, allocate memory and initialize it as 0 */
    return av_mallocz(result);
}