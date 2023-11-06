1)

btc_malloc(size_t size) {
  void *ptr = malloc(size);
  assert(ptr);
  return ptr;
}

2)

btc_malloc(size_t size) {
  void *ptr = calloc(1, size);
  if (ptr == NULL)
    exit(EXIT_FAILURE);
  return ptr;
}

3)

btc_malloc(size_t size) {
  void *ptr;
  if(!(ptr=malloc(size)))
    abort();
  return ptr;
}

4)

btc_malloc(size_t size) {
  void *ptr = malloc(size);
  if (ptr == NULL)
    exit(EXIT_FAILURE);
  return ptr;
}

5)

btc_malloc(size_t size) {
  void *ptr=nullptr;
  while(!(ptr=malloc(size))){};
  return ptr;
}

6)

btc_malloc(size_t size) {
  void *ptr = malloc(size);
  if (ptr == NULL) {
    perror("Error allocating memory");
    exit(EXIT_FAILURE);
  }
  return ptr;
}
