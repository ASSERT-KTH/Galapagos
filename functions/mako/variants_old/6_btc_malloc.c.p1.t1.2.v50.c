btc_malloc(size_t size) {
    void *ptr = malloc(size);

    if (ptr == NULL) {
        printf("Memory allocation failed. Abort...\n");
        exit(EXIT_FAILURE);
    }
  
    memset(ptr, 0, size);  
  
    return ptr;
}