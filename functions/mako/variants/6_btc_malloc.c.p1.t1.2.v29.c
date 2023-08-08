btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    printf("Memory allocation failed.\n");
    exit(1);
  }

  return ptr;
}