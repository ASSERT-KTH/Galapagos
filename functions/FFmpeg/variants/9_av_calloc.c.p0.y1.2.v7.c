void *av_calloc(size_t nmemb, size_t size) {
    size_t total;
    if (size_mult(nmemb, size, &total) < 0)
        return NULL;
    return av_mallocz(total);
}