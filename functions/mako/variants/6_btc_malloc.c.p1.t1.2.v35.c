btc_malloc(size_t size) {
  void *ptr = malloc(size);

  assert(ptr && "Memory allocation failed!");

  return ptr;
}