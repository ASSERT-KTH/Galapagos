checked_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL)
    btc_abort(); /* LCOV_EXCL_LINE */

  return ptr;
}