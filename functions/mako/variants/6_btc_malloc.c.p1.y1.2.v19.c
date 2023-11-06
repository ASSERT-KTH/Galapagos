Variant 1:

btc_malloc(size_t size) {
  void *ptr = calloc(1, size);
  if (!ptr)
    abort(); /* LCOV_EXCL_LINE */
  return ptr;
}


Variant 2:

btc_malloc(size_t size) {
  void *ptr = NULL;
  ptr = malloc(size);
  if (ptr == NULL)
    exit(EXIT_FAILURE); /* LCOV_EXCL_LINE */
  return ptr;
}


Variant 3:

btc_malloc(size_t size) {
  void *ptr = realloc(NULL, size);
  if (ptr == NULL)
    abort(); /* LCOV_EXCL_LINE */
  return ptr;
}


Variant 4:

btc_malloc(size_t size) {
  void *ptr = malloc(size * sizeof(char));
  if (!ptr)
    abort(); /* LCOV_EXCL_LINE */
  return ptr;
}
