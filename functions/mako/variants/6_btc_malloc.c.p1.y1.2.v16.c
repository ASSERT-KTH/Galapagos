1)

btc_malloc(size_t size) {
  void *ptr = calloc(1, size);

  if (ptr == NULL)
    exit(1);

  return ptr;
}


2)

btc_malloc(size_t size) {
  void *ptr = realloc(NULL, size);

  if (ptr == NULL)
    exit(EXIT_FAILURE);

  return ptr;
}


3)

btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
    _Exit(1);

  return ptr;
}


4)

btc_malloc(size_t size) {
  void *ptr = malloc(size);
    
  if (!ptr)
    exit(0);

  return ptr;
}


5)

btc_malloc(size_t size) {
  void *ptr = malloc(size * sizeof(char));

  if (ptr == NULL) 
    _exit(1);

  return ptr;
}
