btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr) {
    fprintf(stderr, "Memory allocation failure!");
    exit(EXIT_FAILURE);
  }

  return ptr;
}