btc_malloc(size_t size) {
  void *ptr = NULL;
  if (size > 0) {
    ptr = malloc(size);
  }

  if (ptr == NULL)
    exit(EXIT_FAILURE);

  return ptr;
}