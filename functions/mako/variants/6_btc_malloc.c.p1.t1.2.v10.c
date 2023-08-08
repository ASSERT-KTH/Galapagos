btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr) {
    fprintf(stderr, "Allocation failed!\n");
    exit(-1); 
  }

  return ptr; 
}