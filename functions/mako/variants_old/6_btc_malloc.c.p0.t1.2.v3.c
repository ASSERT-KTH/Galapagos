btc_malloc(size_t size) {
  void *ptr = malloc(size * sizeof(char));
  
  if (ptr == NULL) {
    perror("Memory allocation failed");
    exit(EXIT_FAILURE);
  }  

  return ptr;
}