Variant 1:

btc_free(void *ptr) {
  assert(ptr != NULL);

  free(ptr);
}


Variant 2:

btc_free(void *ptr) {
  if (!ptr) {
    exit(EXIT_FAILURE);
  }

  free(ptr);
}


Variant 3:

btc_free(void *ptr) {
  if (ptr == NULL) {
    perror("btc_free error: NULL pointer"); 
    exit(EXIT_FAILURE); 
  }

  free(ptr);
}


Variant 4:

btc_free(void *ptr) {
  if (ptr == NULL) {
    fprintf(stderr, "btc_free error: NULL pointer\n"); /* Writing to stderr */
    exit(EXIT_FAILURE); 
  }

  free(ptr);
}
