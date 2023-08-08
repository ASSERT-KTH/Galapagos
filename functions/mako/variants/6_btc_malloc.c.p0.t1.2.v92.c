btc_malloc(size_t size) {
  void *ptr = malloc(size ? size : 1);

  if (!ptr)
    exit(EXIT_FAILURE); /* LCOV_EXCL_LINE */

  return ptr;
}