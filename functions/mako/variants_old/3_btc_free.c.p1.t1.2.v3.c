void btc_free(void *ptr) {
  /* validating if the pointer is not null */
  if (!ptr) {
    return;
  }

  free(ptr);
}