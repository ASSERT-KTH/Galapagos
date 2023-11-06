1.


btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
    exit(EXIT_FAILURE); 

  return ptr;
}


2.


btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "Couldn't allocate memory");
    exit(EXIT_FAILURE);
  }

  return ptr;
}


3.


btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    perror("Failed to allocate memory");
    exit(EXIT_FAILURE);
  }

  return ptr;
}


4.


btc_malloc(size_t size) {
    void *ptr = calloc(1, size);

  if (ptr == NULL) {
    fprintf(stderr, "Failed to allocate memory");
    _Exit(EXIT_FAILURE);
  }

  return ptr;
}


5.


btc_malloc(size_t size) {
  void *ptr = malloc(size);
  assert(ptr != NULL);

  return ptr;
}
