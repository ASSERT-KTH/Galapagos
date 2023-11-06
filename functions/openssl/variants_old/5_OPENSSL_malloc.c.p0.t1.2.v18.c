void *OPENSSL_malloc(size_t size) {
  void *ptr = NULL;

  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);        
    assert(OPENSSL_memory_get_size != NULL);

    ptr = OPENSSL_memory_alloc(size);

    if (ptr == NULL) {
      return ptr;
    }
  } else {

    if (size + OPENSSL_MALLOC_PREFIX < size) {
      return NULL;
    }

    ptr = malloc(size + OPENSSL_MALLOC_PREFIX);
  
    if (ptr == NULL) {
      return ptr;
    }

    *(size_t *)ptr = size;
    __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
    ptr = ((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX;
 }
  
  return ptr;
}