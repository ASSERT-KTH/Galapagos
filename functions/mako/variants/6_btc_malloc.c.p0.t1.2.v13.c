btc_malloc(size_t size) {
  void *ptr = calloc(1, size);

  if (ptr == NULL) {
    perror("Memory allocation error");
    abort();
  } 
  else 
    return ptr;
}