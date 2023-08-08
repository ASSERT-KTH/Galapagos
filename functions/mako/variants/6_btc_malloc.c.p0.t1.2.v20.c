btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "Malloc failed, aborting program.\n");
    abort();
  }

  memset(ptr, 0, size);

  return ptr;
}