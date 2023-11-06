void btc_free(void *ptr) {
  if (!ptr) {
    printf("Error: Trying to free memory at NULL pointer. Aborting...\n");
    exit(EXIT_FAILURE);
  } 

  free(ptr);
  ptr = NULL;
}