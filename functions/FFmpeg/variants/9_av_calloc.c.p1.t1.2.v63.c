void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;

    if (size == 0 || nmemb == 0){
        return NULL;
    }

    result = nmemb * size;    

    if (nmemb != result / size){
       return NULL;
    }

    return av_mallocz(result);
}