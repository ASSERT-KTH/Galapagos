size_t ldb_malloc(size_t size) {
  void *ptr = malloc(size + 1);

  if (!ptr)
    exit(1);

  memset(ptr, 0, size);
  return (size_t)ptr;
}