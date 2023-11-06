void *ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
    exit(-1);

  return ptr;
}