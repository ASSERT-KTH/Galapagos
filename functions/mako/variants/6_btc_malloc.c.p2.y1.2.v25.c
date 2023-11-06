btc_malloc(size_t size) {
    void* ptr = (void*)calloc(1, size);
    if(ptr == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    return ptr;
}