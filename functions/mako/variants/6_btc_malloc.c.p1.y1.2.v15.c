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

  if (ptr == NULL)
    assert(0);

  return ptr;
}


3. 

btc_malloc(size_t size) {
  void *ptr;

  if (!(ptr = malloc(size)))
    abort();

  return ptr;
}


4. 

btc_malloc(size_t size) {
  void *ptr;

  if (!(ptr = malloc(size)))
    _Exit(0);

  return ptr;
}


5. 

btc_malloc(size_t size) {
  void* ptr;

  if (size > 0)
    ptr = malloc(size);

  if (ptr == NULL)
    perror("Failed to allocate memory");

  return ptr;
}


6. 

btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (!ptr)
    fatal("Out of memory");

  return ptr;
}
