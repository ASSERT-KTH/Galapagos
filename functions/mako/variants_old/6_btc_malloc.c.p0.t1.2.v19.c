btc_malloc(size_t size) {
  void *ptr = malloc(size);
  
  if (ptr == NULL) {
    fflush(stderr);
    abort();
  }
  
  return ptr;
}