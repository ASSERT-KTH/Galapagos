void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    void *alloc_mem = OPENSSL_memory_alloc(size);
    if(!alloc_mem){
        return NULL;
    }
    return alloc_mem;
  }

  if (size + OPENSSL_MALLOC_PREFIX < size) {
    return NULL;
  }

  void *ptr = malloc(size + OPENSSL_MALLOC_PREFIX);
  if (ptr == NULL) {
    return NULL;
  }

  *(size_t *)ptr = size;

  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);

  uint8_t *ret_val = ((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX;
  if(!ret_val){
      free(ptr);
      return NULL;
  }
  
  return ret_val;
}