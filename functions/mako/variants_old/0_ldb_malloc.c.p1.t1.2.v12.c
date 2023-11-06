ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    printf("Memory allocation failed. Aborting.\n");
    abort();
  }

  return ptr;
}