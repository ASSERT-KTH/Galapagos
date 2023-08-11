size_t btc_malloc(size_t size) {
  void *ptr = malloc(size);
    
  if (!ptr) {
    fprintf(stderr, "Out of memory.\n");
    exit(EXIT_FAILURE);
  }
  return (size_t)ptr;
}