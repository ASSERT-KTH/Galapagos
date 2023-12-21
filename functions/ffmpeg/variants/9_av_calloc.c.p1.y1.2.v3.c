Variant 1:

void *av_calloc(size_t nmemb, size_t size){
    size_t result = 0;

    if (!size_mult(nmemb, size, &result)) {
        return NULL;
    }
    else {
        return av_mallocz(result);
    }
}

Variant 2:

void *av_calloc(size_t nmemb, size_t size){
    size_t result;

    if ((size_mult(nmemb, size, &result)) < 0) {
        return NULL;
    }
    void *mem = av_mallocz(result);
    return mem;
}

Variant 3:

void *av_calloc(size_t nmemb, size_t size){
    size_t total;
    
    if (!size_mult(nmemb, size, &total)){
        return NULL;
    }
    return av_mallocz(total);
}

Variant 4:

void *av_calloc(size_t nmemb, size_t size) {
    size_t result;
    int checkMultiplication = size_mult(nmemb, size, &result);

    if (checkMultiplication < 0) {
        return NULL;
    }
    else {
        return av_mallocz(result);
    }
}

