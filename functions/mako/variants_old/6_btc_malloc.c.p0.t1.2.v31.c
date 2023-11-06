btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "Memory allocation failed. Program will be terminated.\n");
    abort(); /* LCOV_EXCL_LINE */
  }

  memset(ptr, 0, size);
  return ptr;
}