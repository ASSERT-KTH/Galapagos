Sure, here's one way the code could be modified: 


void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    if (size <= 0 || nmemb <= 0)
       return NULL;
    result =  size * nmemb;
    return av_mallocz(result);
}
