void *btc_malloc(size_t size) {
  void *ptr = calloc(1, size);

  if (!ptr)
    exit(1);

  return ptr;
}