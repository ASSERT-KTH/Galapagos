btc_free(void *ptr) {
  if (ptr == NULL) {
    exit(EXIT_FAILURE); /* change abort() to exit(EXIT_FAILURE) */
    return;
  }

  free(ptr);
  ptr = NULL;
}