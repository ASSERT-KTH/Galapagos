btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    perror("Error: Failed to allocate memory!\n");
    exit(EXIT_FAILURE);
  }
  
  return ptr;
}