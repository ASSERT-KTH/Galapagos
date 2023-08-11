btc_malloc(size_t size) {
  void *ptr;

  ptr = malloc(size);

  if (!ptr) 
    exit(EXIT_FAILURE);

  return ptr;
}