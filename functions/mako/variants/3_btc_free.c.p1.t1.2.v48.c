btc_free(void *ptr) {
  if (!ptr) {
    printf("Error: Attempt to free null pointer!"); /* Additional error message */
    exit(-1);
  }

  free(ptr);
}