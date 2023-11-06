btc_malloc(size_t size) {
    void *address = malloc(size);

    if (!address) exit(EXIT_FAILURE);

    return address;
}