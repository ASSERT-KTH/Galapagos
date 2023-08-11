int ldb_malloc(size_t size) {
  void *ptr = calloc(1, size);

  if (ptr == NULL)
    exit(1);

  return (int)ptr;
}
