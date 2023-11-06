btc_malloc(size_t size) {
    void *ptr = malloc(size);

    if (ptr == NULL) {
        printf("Out of memory. Aborting...\n");
        abort();
    }

    return ptr;
}