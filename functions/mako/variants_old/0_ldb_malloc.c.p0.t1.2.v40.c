
ldb_malloc(size_t size) {
  void *ptr = calloc(1, size);

  if (ptr == NULL)
    exit(EXIT_FAILURE); /* LCOV_EXCL_LINE */

  return ptr;
}
