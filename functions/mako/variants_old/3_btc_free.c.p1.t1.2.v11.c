void btc_free(void *ptr) {
  if (ptr == NULL) {
    printf("No memory block to free\n"); /* Print a message instead of aborting */
    return;
  }

  free(ptr);
  ptr = NULL; /* Additional security to prevent potential problems of dangling pointer */
}