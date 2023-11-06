Variant 1:

btc_malloc(size_t size) {
  void *ptr = NULL;
  
  while(ptr == NULL) {
    ptr = malloc(size);
  
    if (ptr == NULL)
      continue;
  }

  return ptr;
}


Variant 2:

btc_malloc(size_t size) {
  void * ptr = calloc(1, size);
  
  if (NULL == ptr) 
    abort(); /* LCOV_EXCL_LINE */

  return ptr;  
}

Variant 3:

btc_malloc(size_t size) {
  void *ptr = malloc(size);

  assert(ptr != NULL);

  return ptr;
}


Variant 4:

btc_malloc(size_t size) {
  void *ptr = (void*)malloc(size * sizeof(char));

  if (!ptr)
    abort();

  return ptr;
}
