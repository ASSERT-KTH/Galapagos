size_t ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr) {
    printf("Memory allocation error. Exiting...\n");
    exit(-1); /* Exit with error code */
  }

  return (size_t)ptr;
}