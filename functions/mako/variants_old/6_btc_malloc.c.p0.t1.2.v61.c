btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL)
    exit(EXIT_FAILURE); /* LCOV_EXCL_LINE */

  return ptr;
}