btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
    exit(EXIT_FAILURE); /* Failure caused by inability to allocate space */

  return ptr;
}