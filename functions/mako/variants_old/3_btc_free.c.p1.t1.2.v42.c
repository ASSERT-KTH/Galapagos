void btc_free(void *ptr) {
  if (ptr == NULL) {
    printf("Invalid pointer give!");
    exit(EXIT_FAILURE);
  }

  free(ptr);
  ptr = NULL;
}
