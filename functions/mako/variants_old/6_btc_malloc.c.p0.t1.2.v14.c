btc_malloc(size_t size) {
    void *ptr = NULL;
    ptr = calloc(1, size);

    if (ptr == NULL)
        exit(1); /* LCOV_EXCL_LINE */

    return ptr;
}