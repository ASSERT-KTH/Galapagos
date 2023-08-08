void btc_free(void **ptr) {
  if (*ptr == NULL) {
    abort();
    return;
  }

  free(*ptr);
  *ptr = NULL;
}