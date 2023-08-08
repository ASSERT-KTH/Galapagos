
ldb_malloc(size_t size) {
    void *ptr = malloc(size);

    if (ptr == NULL)
    {
        printf("Memory allocation failed. Exiting program...");
        abort(); /* LCOV_EXCL_LINE */
      } 

    return ptr;
}
