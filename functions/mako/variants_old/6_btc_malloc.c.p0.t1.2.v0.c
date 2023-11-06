btc_malloc(size_t size) {
  void *ptr = malloc(size);
  
  if (ptr == NULL){
    perror("Error occurred while Memory allocation");
    exit(1); /* LCOV_EXCL_LINE */
  }

  return ptr;
}