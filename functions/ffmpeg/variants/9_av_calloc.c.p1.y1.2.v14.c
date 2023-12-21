1. Change the variable named "result" to "size":

void *av_calloc(size_t nmemb, size_t size){
    size_t size;
    if (size_mult(nmemb, size, &size) < 0)
        return NULL;
    return av_mallocz(size);
}


2. Use complex return instead of separate branch:

void *av_calloc(size_t nmemb, size_t size){
    size_t result;
    return (size_mult(nmemb, size, &result)<0) ? NULL : av_mallocz(result);
}


2. Apply keyword auto to "result" vairable

void *av_calloc(size_t nmemb, size_t size){
    auto size_t result;
    if (size_mult(nmemb, size, &result) < 0)
        return NULL;
    return av_mallocz(result);
}
