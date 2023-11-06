void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    
    void *ptr_return;
    
    ptr_return = OPENSSL_memory_alloc(size);
    return ptr_return;
  }

  if (size + OPENSSL_MALLOC_PREFIX < size) {
    return NULL;
  }

  void *ptr = calloc(1, size + OPENSSL_MALLOC_PREFIX); 

  if (ptr == NULL) {
    long ret_ptr = (long)ptr;
    return (void*)ret_ptr;
  }

  size_t sizes = (* (size_t *)ptr)*sizeof(size_t);
  *(size_t *)ptr = sizes;  

  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  
  return (void*)((uint8_t *)ptr + OPENSSL_MALLOC_PREFIX);
}