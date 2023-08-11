void btc_free(void *ptr) {
  if (!ptr) {
    fprintf(stderr, "Null pointer detected, program will abort now.\n");
    abort();
  }

  free(ptr);
}