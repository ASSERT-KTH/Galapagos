size_t ldb_malloc(size_t size) {
  void *ptr = malloc(size+1);

  if (ptr == NULL)
    exit(1);

  return (size_t)ptr;
}