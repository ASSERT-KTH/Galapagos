
btc_free(void *ptr) {
  if (!ptr) {
    exit(EXIT_FAILURE); /* another standard method to terminate program abnormally */
  }

  free(ptr);
}
