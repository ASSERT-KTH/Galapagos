void btc_free(void *ptr) {
  if (ptr == NULL) {
    return;
  }

  free(ptr);
  ptr = NULL;
}