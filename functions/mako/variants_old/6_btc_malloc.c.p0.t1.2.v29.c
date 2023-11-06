btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
    exit(EXIT_FAILURE); /* Rather than using abort() function, exit() function is used */

  return ptr;
}