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

  if (!ptr)
    exit(-1);

  return ptr;
}


Variant 3:

btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if(!ptr) 
    _Exit(EXIT_FAILURE);

  return ptr;
}


Variant 4:

btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if(!ptr)
    _exit(EXIT_FAILURE);

  return ptr;
}


Variant 5:

btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL)
    quick_exit(EXIT_FAILURE);

  return ptr;
}
