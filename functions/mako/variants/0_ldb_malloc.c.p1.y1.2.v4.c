Variant 1:

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
    exit(EXIT_FAILURE); /* LCOV_EXCL_LINE */

  return ptr;
}


Variant 2:

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  ptr == NULL ? abort() : NULL; /* LCOV_EXCL_LINE */

  return ptr;
}


Variant 3:

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL)
    exit(1); /* LCOV_EXCL_LINE */

  return ptr;
}


Variant 4:

void* ldb_malloc(size_t size) {
  void *ptr = calloc(1, size);

  if (ptr == NULL)
    abort(); /* LCOV_EXCL_LINE */

  return ptr;
}


Variant 5:

void* ldb_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL)
    _Exit(-1); /* LCOV_EXCL_LINE */

  return ptr;
}
