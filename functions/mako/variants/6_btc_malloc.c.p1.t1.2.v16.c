
btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "memory allocation failed, aborting...\n"); /* Change: detail allocation failure */
    abort();
  }

  return ptr;
}
