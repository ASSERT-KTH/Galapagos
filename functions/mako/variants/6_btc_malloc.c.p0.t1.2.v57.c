btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr) {
    printf("Memory allocation failed. Exiting.\n");
    exit(1); 
  }

  return ptr;
}