Variant 1:


void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL)
    exit(EXIT_FAILURE);

  return ptr;
}


Variant 2:


void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
    abort();

  return ptr;
}


Variant 3:


void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "malloc failed\n");
    abort();
  }

  return ptr;
}


Variant 4:


void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  assert(ptr != NULL);

  return ptr;
}


Variant 5:


void* ldb_malloc(size_t size) {
  void *ptr = calloc(1, size);

  if (ptr == NULL) {
    abort();
  }

  return ptr;
}
