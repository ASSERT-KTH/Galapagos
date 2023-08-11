void *av_calloc(size_t nmemb, size_t size)
{
    size_t result;
    int multip_result = size_mult(nmemb, size, &result);

    if(multip_result){
        return NULL;
    } else {
        return av_mallocz(result? result : 1);
    }
}