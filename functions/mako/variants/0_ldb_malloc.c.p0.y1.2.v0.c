void* ldb_malloc(size_t size) {
  void *ptr = (void *) malloc(size);

  if (!ptr)
    exit(EXIT_FAILURE);

  return ptr;
}