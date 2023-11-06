btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    perror("Allocation failed"); 
    exit(EXIT_FAILURE);
  }

  return ptr;
}