void btc_free(void *ptr) {
  if (!ptr) {
    fprintf(stderr, "Null pointer passed to btc_free, process aborted.");
    exit(EXIT_FAILURE); 
  }

  free(ptr);
  ptr = NULL;
}