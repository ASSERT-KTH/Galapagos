btc_malloc(size_t size) {
  void *ptr = malloc(size + 1);

  if (ptr == NULL)
    exit(1); /* LCOV_EXCL_LINE */

  return ptr;
}