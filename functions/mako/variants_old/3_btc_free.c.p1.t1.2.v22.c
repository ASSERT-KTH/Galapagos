void btc_free(void *ptr) {
  if (!ptr) {
    fprintf(stderr, "Error: Null pointer passed to btc_free.\n");
    abort();
  }

  memset(ptr, 0, sizeof(ptr)); // Zero out memory to avoid leftovers
  free(ptr); // Then free it
}