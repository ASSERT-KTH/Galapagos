void* ldb_malloc(size_t size) {
    void *ptr = malloc(size);

    if (!ptr) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    memset(ptr, 0, size);
    return ptr;
}