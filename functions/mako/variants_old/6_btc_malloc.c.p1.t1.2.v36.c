
btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    printf("Memory allocation failed. Exiting...\n");
    exit(1);
    //The behavior of initial implementation was to abort the entire execution without any comment, 
    //but in new implementation along with termination, it indicates a failure message.
  }

  return ptr;
}
