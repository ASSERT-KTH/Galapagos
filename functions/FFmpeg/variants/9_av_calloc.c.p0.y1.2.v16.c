void* av_calloc(size_t nmemb, size_t size)
{
    size_t result = nmemb * size;

    if (result / size != nmemb)  //checks for overflow during multiplication
        return NULL;

    return av_mallocz(result);
}