btc_free(void *ptr) {
  if (ptr == NULL) {
    // For this variant we're hiding the abort call behind a tracing call.
    // Useful to logger the error without stop the programmed execution.
    fprintf(stderr, "NULL pointer error in btc_free function. Expected valid pointer, received NULL.\n"); 
  } else {
    free(ptr);
    ptr = NULL; /* Possibly unnecessary, but added here to ensure that the passed pointer is not used after free up the memory */
  }
}