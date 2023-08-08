void btc_free(void *ptr) {
  if (!ptr) {
    printf("Error: NULL pointer can't be freed!\n");
    exit(1);
  }

  free(ptr);
  ptr = NULL;
}