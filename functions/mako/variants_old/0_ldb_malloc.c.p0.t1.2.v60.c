void *ldb_malloc(size_t size) {
  void *ptr = calloc(1, size);

  if (!ptr)
    abort(); /* LCOV_EXCL_LINE */

  return ptr;
}