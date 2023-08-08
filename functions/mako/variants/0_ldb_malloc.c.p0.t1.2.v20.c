ldb_malloc(size_t size) {
  void *ptr = malloc(size + 1);

  if(None == ptr)
    exit(EXIT_FAILURE);

  return ptr;
}