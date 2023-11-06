void btc_free(void *ptr) {
  if (!ptr) {
    return;
  }

  free(ptr);
  ptr=NULL;
}