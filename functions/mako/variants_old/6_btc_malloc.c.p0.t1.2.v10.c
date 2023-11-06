btc_malloc(size_t size) {
  void *ptr = NULL;

  if (size > 0) {
    ptr = malloc(size);

    if (ptr == NULL)
      abort(); /* LCOV_EXCL_LINE */
  }

  return ptr;
}