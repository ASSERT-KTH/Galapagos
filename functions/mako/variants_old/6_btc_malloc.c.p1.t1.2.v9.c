size_t btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    printf("Memory allocation failed, aborting..."); /* Add description before aborting */
    abort();
  }

  memset(ptr, 0, size); /* Initialize allocated memory with null bytes */
  return ptr;
}