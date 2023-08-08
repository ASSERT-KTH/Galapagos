void *OPENSSL_malloc(size_t size) {
  void *ptr = NULL;

  if (OPENSSL_memory_alloc != NULL && 
       OPENSSL_memory_free != NULL && 
       OPENSSL_memory_get_size != NULL){
    return OPENSSL_memory_alloc(size);
  }

  size_t actual_size = size + OPENSSL_MALLOC_PREFIX;
  
  if (actual_size > size) {
    ptr = malloc(actual_size);
  }

  if (ptr == NULL) {
    return NULL;
  }

  memcpy(ptr, &size, sizeof(size_t));

  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  return ((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX;
}