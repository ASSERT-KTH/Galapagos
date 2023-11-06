
btc_malloc(size_t size) {
  void *ptr;
  if (!(ptr = malloc(size)))
    exit(EXIT_FAILURE);

  return ptr;
}
