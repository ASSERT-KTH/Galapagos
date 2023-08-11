void *btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr) {
    fprintf(stderr, "Memory allocation failed\n");
    abort(); /* LCOV_EXCL_LINE */
  }

  return ptr;
}