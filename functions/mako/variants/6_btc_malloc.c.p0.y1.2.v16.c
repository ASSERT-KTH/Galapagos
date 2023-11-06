void* btc_malloc(size_t size) {
  void *ptr = (void*) calloc(1, size);

  if (!ptr)
    exit(EXIT_FAILURE);

  return ptr;
}