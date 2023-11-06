Variant 1:

btc_malloc(size_t size) {
  void *ptr = NULL;
  ptr = malloc(size);

  if (ptr == NULL)    
    exit(EXIT_FAILURE);

  return ptr;
}


Variant 2:

btc_malloc(size_t size) {
  void *ptr = calloc(1, size);

  if (ptr == NULL)
    exit(-1);

  return ptr;
}


Variant 3:

btc_malloc(size_t size) {
  void *ptr = malloc(size);
  
  while(ptr == NULL){
      sleep(1); // Wait for 1 sec
      ptr = malloc(size); // Try again to allocate memory
  }

  if (ptr == NULL)
    assert(ptr); // the context is incorrect
  
  return ptr;
}


Variant 4:

btc_malloc(size_t size) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    fprintf(stderr, "Failed to allocate memory!\n");
    abort();    
  }

  return ptr;
}


Variant 5:

btc_malloc(size_t size) {
  void *ptr = malloc(size);
  assert(ptr);
  return ptr;
}
