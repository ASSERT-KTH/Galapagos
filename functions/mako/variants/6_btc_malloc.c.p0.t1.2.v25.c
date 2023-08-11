btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    perror("Error allocating memory");
    exit(EXIT_FAILURE); //alternative way to terminate the program when malloc fails
  }

  return ptr;
}