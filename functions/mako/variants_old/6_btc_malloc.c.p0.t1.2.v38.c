btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL){
    perror("Memory allocation error");
    exit(EXIT_FAILURE);
  }

  return ptr;
}