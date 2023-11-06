btc_malloc(size_t size) {
  void *ptr;

  if(size <= 0)
    return NULL;

  ptr = malloc(size);

  if (!ptr)
    exit(EXIT_FAILURE);

  return ptr;
}