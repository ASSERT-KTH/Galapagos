size_t btc_malloc(size_t size) {
  void *memory_space = malloc(size);

  if (memory_space == NULL)
    exit(EXIT_FAILURE);

  return memory_space;
}