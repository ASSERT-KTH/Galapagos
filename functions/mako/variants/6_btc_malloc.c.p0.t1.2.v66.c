btc_malloc(size_t size) {
  void *ptr;
  if (size > 0) {
    ptr = malloc(size);

    if (ptr == NULL) {
      fprintf(stderr, "Unable to allocate memory!\n");
      exit(EXIT_FAILURE);
    }
  }
  else {
    ptr = NULL;
  }

  return ptr;
}