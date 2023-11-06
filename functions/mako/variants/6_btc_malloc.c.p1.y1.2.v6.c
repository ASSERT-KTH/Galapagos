Variant 1:

btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
    exit(EXIT_FAILURE);

  return ptr;
}

Variant 2:

btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == 0)
    _Exit(1);

  return ptr;
}

Variant 3:

btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL)
    quick_exit(1);

  return ptr;
}

Variant 4:

btc_malloc(size_t size) {
  void *ptr = calloc(1, size);

  if (NULL == ptr)
    abort();

  return ptr;
}

Variant 5:

btc_malloc(size_t size) {
  void *ptr = realloc(NULL, size);

  if (NULL == ptr)
    abort();

  return ptr;
}
