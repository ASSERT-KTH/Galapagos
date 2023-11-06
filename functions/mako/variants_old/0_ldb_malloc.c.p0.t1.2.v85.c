void* ldb_malloc(size_t size) {
    void *ptr = malloc(size);

    if (ptr == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    memset(ptr, 0, size); 

    return ptr;
}