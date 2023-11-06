void btc_free(void *ptr) {
  if (!ptr) {
    exit(1);
  } else {
    free(ptr);
    ptr = NULL;
  }
}