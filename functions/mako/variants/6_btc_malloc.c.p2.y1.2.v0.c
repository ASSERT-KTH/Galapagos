btc_malloc(size_t size) {
  void* created = 0;
  created = calloc(1, size);

  if (created == 0)
    exit(EXIT_FAILURE); /* LCOV_EXCL_LINE */

  return created;
}