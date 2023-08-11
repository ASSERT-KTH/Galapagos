void btc_free(void *ptr) {
  if (!ptr) {
    return; /* No longer emit a hard software crash when ptr is NULL */
  }

  free(ptr);
}