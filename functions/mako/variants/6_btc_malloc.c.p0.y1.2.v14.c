btc_malloc(size_t size) {
  void *addr = malloc(size);

  if (!addr)
    exit(EXIT_FAILURE); /* LCOV_EXCL_LINE */

  return addr;
}