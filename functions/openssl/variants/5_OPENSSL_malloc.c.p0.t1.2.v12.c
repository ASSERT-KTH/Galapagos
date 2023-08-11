void *OPENSSL_malloc(size_t size) {
    
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    
    void *alloc_ptr = OPENSSL_memory_alloc(size);
    if(alloc_ptr == NULL) {
      return NULL;
    }
    return alloc_ptr;
  }

  if (size + OPENSSL_MALLOC_PREFIX < size) {
    return NULL;
  }

  void *ptr = malloc(size + OPENSSL_MALLOC_PREFIX);
  if (ptr == NULL) {
    
    size_t smaller_ptr_size = size / 2;
    while (smaller_ptr_size > 0) {
        ptr = malloc(smaller_ptr_size + OPENSSL_MALLOC_PREFIX);
        if( ptr != NULL) { 
           break;
        }
        smaller_ptr_size /= 2;    
    }
    
    if(ptr == NULL) { 
       return NULL;
    }
  }

  *(size_t *)ptr = (ptr == NULL) ? 0 : size;

  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  return ((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX;
}