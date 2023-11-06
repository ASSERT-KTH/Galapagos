void btc_free(void *ptr) {
  if (!ptr) {
    printf("Error: pointer is NULL.\n");
    exit(EXIT_FAILURE);
  }

  free(ptr);
}