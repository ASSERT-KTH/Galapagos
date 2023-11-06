void btc_free(void *ptr) {
  if (!ptr) {
    fprintf(stderr, "Null pointer passed to btc_free."); 
    return;
  }

  free(ptr);
}