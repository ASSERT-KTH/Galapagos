void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
  
    if ((result = nmemb * size) != 0 && (nmemb > (SIZE_MAX / size))) {
        return NULL;
    }
  
    return av_mallocz(result);
}