
ldb_malloc(size_t size) {
  void *ptr = malloc(sizeof(char) * size);

  if (ptr == 0)
    exit(EXIT_FAILURE); /* LCOV_EXCL_LINE */

  return ptr;
}
