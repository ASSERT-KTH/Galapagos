void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr) {
    exit(EXIT_FAILURE);  /* Exit instead of abort to avoid core dump */
  }

  return ptr;
}