Variant 1:

void* ldb_malloc(size_t size) {
  void *ptr = NULL;

  if (!(ptr = malloc(size))) {
    abort();
  }

  return ptr;
}

Variant 2:

void* ldb_malloc(size_t size) {
  void *ptr = (char*)malloc(size * sizeof(char));

  if (ptr == NULL)

    exit(EXIT_FAILURE); 

  return ptr;
}


Variant 3:

void* ldb_malloc(size_t size) {
  void *ptr = calloc(size, sizeof(char));

  if (ptr == NULL)
    abort();

  return ptr;
}


Variant 4:

void* ldb_malloc(size_t size) {
  void* ptr = NULL;
  ptr = malloc(size);

  if (!ptr) {
    abort();
  }

  return ptr;
}


Variant 5:

void* ldb_malloc(size_t size) {
  void *ptr;

  if((ptr = malloc(size)) == NULL) {
    abort();
  }

  return ptr;
}
