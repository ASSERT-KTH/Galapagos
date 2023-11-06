void* btc_malloc(size_t size) {
  void *ptr;

  while((ptr = malloc(size)) == NULL) {}

  return ptr;
}