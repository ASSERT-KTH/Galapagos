
btc_malloc(size_t size) {
    void *ptr = malloc(size);

    if (!ptr)
        exit(EXIT_FAILURE);

    return ptr;
}



btc_malloc(size_t size) {
    void *ptr;

    if ((ptr = malloc(size)) == NULL)
        quick_exit(1);

    return ptr;
}
 


btc_malloc(size_t size) {
    void *ptr = malloc(size);

    if(ptr == NULL) {
        perror("Memory Allocation Error");
        _Exit(1);
    }

    return ptr;
}
