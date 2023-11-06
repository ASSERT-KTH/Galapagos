btc_free(void *ptr) {
  if (!ptr) {
    abort();
  } else {
    free(ptr);
  }
}