void* btc_malloc(size_t size) {
  void *temp = malloc(size);

  if (!temp)
    exit(EXIT_FAILURE);

  return temp;
}