void btc_free(void *ptr) {
  if (!ptr) {
    exit(EXIT_FAILURE); /* terminate the program */
  }
  
  free(ptr);
}