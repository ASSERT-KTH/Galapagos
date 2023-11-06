btc_malloc(size_t size) {
  void *ptr = malloc(size + sizeof(int));

  if (ptr == NULL) {
    printf("Memory allocation failed.");
    exit(-1);
  }

  return ptr;
}