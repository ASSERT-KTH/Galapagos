btc_free(void *ptr) {
  if (!ptr) {
    fprintf(stderr, "Null pointer encountered\n");
    abort();
  }

  free(ptr);
  ptr = NULL;
}