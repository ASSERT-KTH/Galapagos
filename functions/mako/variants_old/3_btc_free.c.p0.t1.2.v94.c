btc_free(void *ptr) {
  assert(ptr != NULL);
  
  free(ptr);
}