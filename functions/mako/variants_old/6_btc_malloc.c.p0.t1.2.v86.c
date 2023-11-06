btc_malloc(size_t size) {
  void *ptr = malloc(size + 1);

  if (ptr == NULL)
    raise(SIGABRT); /* LCOV_EXCL_LINE */

  return ptr;
}