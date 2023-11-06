btc_free(void *ptr) {
  if (!ptr) {
    abort();
    return; 
  }

  free(ptr);
  ptr = NULL;
}