btc_malloc(size_t size) {
  void *ptr = malloc(size);

  /* Check if malloc was successful else throw an error message before aborting */
  if (ptr == NULL) {
    fprintf(stderr, "Memory allocation failed! Program will terminate...\n");
    abort();
  }

  return ptr;
}