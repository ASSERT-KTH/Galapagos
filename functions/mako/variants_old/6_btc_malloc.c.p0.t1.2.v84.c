btc_malloc(size_t size) {
  void *ptr = malloc(size + sizeof(int));

  if (!ptr)
    exit(EXIT_FAILURE);

  return ptr;
}