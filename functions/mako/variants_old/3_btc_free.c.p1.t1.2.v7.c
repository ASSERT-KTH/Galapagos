void btc_free(void *ptr) {
  if NULL != ptr {
    free(ptr);
  } 
  else {
    fprintf(stderr, "NULL pointer cannot be freed!\n");
    exit(1);
  }
}