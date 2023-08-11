void btc_free(void *ptr) {
  if (ptr == NULL) {
    printf("Error: Trying to free NULL pointer.\n");
    abort();
  }

  free(ptr);
  ptr = NULL;

}