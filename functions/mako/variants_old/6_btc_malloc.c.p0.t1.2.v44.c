btc_malloc(size_t size) {
  void *ptr = malloc(size + 1);

  if (ptr == NULL)
    exit(1); 

  memset(ptr, 0, size + 1);

  return ptr;
}