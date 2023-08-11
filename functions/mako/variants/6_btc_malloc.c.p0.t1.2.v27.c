btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL){
    printf("Allocation failed! Exiting ...");
    exit(1); /* LCOV_EXCL_LINE */
  }
      
  return ptr;
}