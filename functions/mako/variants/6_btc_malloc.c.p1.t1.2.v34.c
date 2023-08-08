btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "Memory allocation failed!\n"); /* Include an error message */
    abort();
  }

  return ptr;
}