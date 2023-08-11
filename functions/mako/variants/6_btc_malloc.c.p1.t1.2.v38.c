btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr) {
    fprintf(stderr, "Memory allocation failed. Exiting..\n");
    exit(EXIT_FAILURE);    
  }

  return ptr;
}