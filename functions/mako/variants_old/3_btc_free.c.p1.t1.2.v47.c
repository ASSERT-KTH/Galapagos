void btc_free(void *ptr) {
  if (ptr == NULL) {
    printf("Error: attempt to free null pointer\n");
    exit(EXIT_FAILURE); /* Aborts program specifically when a NULL pointer is attempted to be freed */
  }

  free(ptr);
}