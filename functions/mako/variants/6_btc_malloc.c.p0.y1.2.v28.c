void *btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
    exit(EXIT_FAILURE); /* Change abort() to exit(EXIT_FAILURE) */

  return ptr;
}