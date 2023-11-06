btc_malloc(size_t size) {
  void *ptr = malloc(size + 1);

  if (ptr == NULL)
    exit(EXIT_FAILURE);

  memset(ptr, 0, size + 1);
  
  return ptr;
}