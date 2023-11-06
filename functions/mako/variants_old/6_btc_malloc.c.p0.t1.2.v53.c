btc_malloc(size_t size) {
  void *tmp = malloc(size);
  
  if (tmp == NULL) {
    fprintf(stderr, "Allocation error\n"); /* Change abort() function with error message */
    exit(EXIT_FAILURE); /* Ensure the termination on failure */
  }
  
  void *ptr = tmp;
  
  return ptr; /* Return dynamically create object's pointer */
}