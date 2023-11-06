btc_free(void *ptr) {
  if (!ptr) {
    printf("NULL pointer cannot be freed. Application will be terminated.\n");
    exit(EXIT_FAILURE);
  }

  free(ptr);
}