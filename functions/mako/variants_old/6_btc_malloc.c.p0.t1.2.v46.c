btc_malloc(size_t size) {
  void *ptr = NULL;
  
  ptr = malloc(size);
  if (ptr == NULL){
    printf("Memory allocation failed!\n");
    exit(EXIT_FAILURE);
  }

  return ptr;
}