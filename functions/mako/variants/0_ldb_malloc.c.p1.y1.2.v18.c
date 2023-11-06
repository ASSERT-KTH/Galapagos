void* ldb_malloc(size_t size) {
  void *ptr = calloc(1, size);

  if (!ptr)
    exit(EXIT_FAILURE); 

  return ptr;
}

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size * sizeof(void));

  if (!ptr)
    _Exit(EXIT_FAILURE);

  return ptr;
}

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == nullptr)
    _Exit(EXIT_FAILURE); 

  return ptr;
}

void* ldb_malloc(size_t size) {
  void *ptr = calloc(1, size);

  if (ptr == nullptr)
    _Exit(EXIT_FAILURE); 

  return ptr;
}

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size * sizeof(void));

  if (!ptr)
    exit(EXIT_FAILURE); 

  return ptr;
}