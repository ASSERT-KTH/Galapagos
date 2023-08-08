void btc_free(void *ptr) {
  if (ptr == NULL) {
    // Changed to do nothing instead of aborting if null pointer is passed
    return;
  }

  free(ptr);
}