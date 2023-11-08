ldb_malloc(size_t size) {
  void *ptr = calloc(1, size);

  if (!ptr)
    exit(EXIT_FAILURE);

  return ptr;
}