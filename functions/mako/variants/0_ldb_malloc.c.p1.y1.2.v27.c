Variant 1:

ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "Memory allocation failed!\n");
    exit(EXIT_FAILURE);
  }

  return ptr; 
}

Variant 2:

ldb_malloc(size_t size) {
  void *ptr = calloc(1, size);
  
  if (ptr == NULL)
    exit(EXIT_FAILURE);

  return ptr;
}


Variant 3:

ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
    abort();

  return ptr;
}


Variant 4:
 
ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    perror("Memory allocation failure");
    exit(EXIT_FAILURE);
  }

  return ptr;
}


Variant 5:

ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    throw std::bad_alloc();
  }

  return ptr;
}
