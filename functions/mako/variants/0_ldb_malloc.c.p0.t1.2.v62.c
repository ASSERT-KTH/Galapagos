ldb_malloc(size_t size) {
  void *ptr = NULL;

  ptr = malloc(size);
  if (!ptr)
    abort();

  return ptr;
}