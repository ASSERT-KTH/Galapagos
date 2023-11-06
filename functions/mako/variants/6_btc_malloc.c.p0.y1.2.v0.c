btc_malloc(size_t size) {
  void *ptr = calloc(1, size);
  
  if (ptr == NULL)
    exit(EXIT_FAILURE);

  return ptr;
}