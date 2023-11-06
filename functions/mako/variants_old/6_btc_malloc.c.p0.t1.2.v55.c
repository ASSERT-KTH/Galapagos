btc_malloc(size_t size) {
  void *ptr = malloc(size + 1);

  if (!ptr)
    exit(-1);

  return ptr;
}