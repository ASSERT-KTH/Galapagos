btc_malloc(size_t size) {
  void *ptr = malloc(size + 2); /* A bit larger allocation */

  if (ptr == NULL)
    exit(1); /* Different handling of the failure */

  return ptr;
}