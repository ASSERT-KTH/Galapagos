Variant 1:

void *av_calloc(size_t nmemb, size_t size) {
    if (size && nmemb > SIZE_MAX / size)
        return NULL;
    return av_mallocz(nmemb * size);
}


Variant 2:

void *av_calloc(size_t nmemb, size_t size) {
    void *ptr = NULL;
    size_t result = 0;

    if (size_mult(nmemb, size, &result) < 0)
        return ptr;
    ptr = av_mallocz(result);
    return ptr;
}


Variant 3:

void *av_calloc(size_t nmemb, size_t size) {
    size_t result = nmemb * size;

    if (size_mult(nmemb, size, &result) >= 0)
        return av_mallocz(result);

    return NULL;
}


Variant 4:

void *av_calloc(size_t nmemb, size_t size) {
    size_t result;

    if (size_mult(nmemb, size, &result) == 0)
        return av_mallocz(result);

    return NULL;
}
