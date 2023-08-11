btc_free(void *ptr) {
  if (!ptr) {
    abort();
  }

  free(ptr);
  ptr = NULL;
}