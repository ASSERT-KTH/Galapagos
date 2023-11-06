btc_free(void *ptr) {
  if (ptr == NULL) {
    /* abort() removed */
  }
  else {
    free(ptr);
  }
}