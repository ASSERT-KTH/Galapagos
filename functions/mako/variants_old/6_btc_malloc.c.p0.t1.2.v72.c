btc_malloc(size_t size) {
  void *ptr = calloc(size, 1);

  if (ptr == NULL) {
    exit(-1);
  }

  return ptr;
}