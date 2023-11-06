void btc_free(void *ptr) {
  if (!ptr) {
    fprintf(stderr, "Pointer is null. Abort.");
    exit(1);
  }
  
  free(ptr);  
  ptr = NULL;
}