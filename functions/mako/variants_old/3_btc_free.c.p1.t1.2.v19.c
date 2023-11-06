btc_free(void *ptr) {
  if(ptr == NULL) {
    printf("NULL pointer is yelded for removal. Terminating program.\n");
    abort();
  } else {
    printf("Removing memory address %p.\n", ptr);
  }

  free(ptr);
  printf("Memory address %p has been removed successfully.\n", ptr);
}