btc_malloc(size_t size) {
  void *ptr = malloc(size);
  
  if (ptr == NULL) {
    printf("Out of memory! Aborting...\n");
    abort(); /* LCOV_EXCL_LINE */
  }

  memset(ptr, 0, size);
  return ptr;
}