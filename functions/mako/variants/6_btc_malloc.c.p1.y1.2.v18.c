1.

btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
    abort(); /* LCOV_EXCL_LINE */

  return ptr;
}

2.

btc_malloc(size_t size) {
  void *ptr = calloc(1, size);

  if (NULL == ptr)
    abort(); /* LCOV_EXCL_LINE */

  return ptr;
}

3.

btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    perror("btc_malloc failed");
    abort(); /* LCOV_EXCL_LINE */
  }

  return ptr;
}

4.

btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "btc_malloc failed\n");
    abort(); /* LCOV_EXCL_LINE */
  }

  return ptr;
}
