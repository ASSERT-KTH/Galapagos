void btc_free(void *ptr) {
  if (ptr == NULL) {
    // No-op 
  } else {
    free(ptr);
  }
}