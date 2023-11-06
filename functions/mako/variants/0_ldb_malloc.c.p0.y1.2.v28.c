ldb_malloc(size_t size) {
    void *p = malloc(size);
    if (!p) {
        exit(EXIT_FAILURE);  /* If malloc() failed, terminate program */
    }
    return p;
}