
btc_free(void *ptr) {
  if (ptr == NULL) {
    printf("Null pointer passed to btc_free. Aborting program.\n");
    abort();
  }

  free(ptr);
}
