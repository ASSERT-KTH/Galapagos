void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    return OPENSSL_memory_alloc(size);
  }
  
  //Adding an elementary check for 0 size input, preserving the function's correctness but slightly altering its behavior
  if (size == 0) {
    return NULL;
  }

  if (size + OPENSSL_MALLOC_PREFIX < size) {
    return NULL;
  }
  
  void *ptr = NULL;
  
  ptr = malloc(size + OPENSSL_MALLOC_PREFIX);
  
  //Check if ptr memory assignment was successful
  if (ptr != NULL) {
    *(size_t *)ptr = size;
  
    __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
    ptr = ((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX;
  }

  return ptr;
}