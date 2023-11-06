void btc_free(void *ptr) {
  if (!ptr) {
    printf("Error: Attempting to free a NULL pointer.\n");
    exit(EXIT_FAILURE);
  }

  free(ptr);
  ptr = NULL;
}