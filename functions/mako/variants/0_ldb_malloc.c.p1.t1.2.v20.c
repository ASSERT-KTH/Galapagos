ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr) {
    fprintf(stderr, "Memory allocation failed: %s/n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  return ptr;
}