size_t btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL){
    fprintf(stderr, "Memory allocation failed!\n"); 
    exit(1); 
  }

  return (size_t)ptr;
}