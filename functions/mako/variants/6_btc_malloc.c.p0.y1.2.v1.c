void* btc_malloc(size_t size) {
    void *ptr;
    
    if ((ptr = malloc(size)) == NULL)
        exit(EXIT_FAILURE); /* LCOV_EXCL_LINE */

    return ptr;
}