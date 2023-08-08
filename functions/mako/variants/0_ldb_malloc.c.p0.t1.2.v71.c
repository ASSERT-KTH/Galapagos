ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
    exit(EXIT_FAILURE); /* LCOV_EXCL_LINE */

  memset(ptr, 0, size);
  
  return ptr;
}