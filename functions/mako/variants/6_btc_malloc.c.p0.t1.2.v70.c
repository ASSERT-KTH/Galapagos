btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    perror("Failed to allocate memory");// enhancement to print specific error details
    exit(EXIT_FAILURE); // change of exit functionality preserving behavior
      
  }
  
  memset(ptr, 0, size); //initializing the allocated memory to zero.

  return ptr;
}