size_t ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "Allocation failed!");
    exit(EXIT_FAILURE);
  }

  return ptr;
}