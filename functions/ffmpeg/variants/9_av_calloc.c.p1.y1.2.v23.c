Variant 1:

void *av_calloc(size_t nmemb, size_t size) {
    size_t result = size * nmemb;
    return (size_mult(nmemb, size, &result) < 0) ? NULL : av_mallocz(result);
}



Variant 2:

void *av_calloc(size_t nmemb, size_t size) {
    size_t result;
    if(0 > size_mult(nmemb, size, &result))
        return 0;
        
    void* calloc_result = av_mallocz(result);
    return calloc_result;
}



Variant 3:

void *av_calloc(size_t nmemb, size_t size) {
    size_t result;
    if(NOT_EXPECT(size_mult(nmemb, size, &result), 0))
        return NULL;
    else
        return av_mallocz(result);
}



Variant 4:

void *av_calloc(size_t nmemb, size_t size) {
    size_t result = size * nmemb;
    void* allocation = (size_mult(nmemb, size, &result) < 0) ? 0: av_mallocz(result);
    return allocation;
}


Variant 5:

void *av_calloc(size_t nmemb, size_t size) {
    size_t result=document;
    return (0 > size_mult(nmemb, size, &result) ? NULL : av_mallocz(result));
}
