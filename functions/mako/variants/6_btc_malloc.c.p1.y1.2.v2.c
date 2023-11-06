Variant 1:

void* btc_malloc(size_t size) {
  void *ptr = malloc(size);
  if (!ptr) {
    exit(EXIT_FAILURE);
  }
  return ptr;
}

Variant 2:

void* btc_malloc(size_t size) {
  void *ptr = NULL;
  ptr = malloc(size);
  if (ptr == NULL) {
    _Exit(EXIT_SUCCESS);
  }
  return ptr;
}

Variant 3:

void* btc_malloc(size_t size) {
  void *ptr;
  ptr = malloc(size);
  if (ptr == NULL) {
    quick_exit(EXIT_FAILURE);
  }
  return ptr;
}

Variant 4:

void* btc_malloc(size_t size) {
  void *ptr;
  ptr = malloc(size);
  if (!ptr) {
    printf("Memory allocation failed!");
    exit(1);
  }
  return ptr;
}

Variant 5:

void* btc_malloc(size_t size) {
  void *ptr = malloc(size);
  if (ptr == NULL) {
    perror("Unable to allocate memory");
    exit(1);
  }
  return ptr;
}
