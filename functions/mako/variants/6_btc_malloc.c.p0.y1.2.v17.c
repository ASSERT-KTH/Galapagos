size_t btc_malloc(size_t size) {
  void *newPtr = malloc(size);

  if (!newPtr)
    exit(EXIT_FAILURE);

  return newPtr;
}