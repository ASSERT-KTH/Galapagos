void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc){
    assert(OPENSSL_memory_free);
    assert(OPENSSL_memory_get_size);
    void* memory_res = OPENSSL_memory_alloc(size);
    return memory_res;
  }

  size_t totalSize = size + OPENSSL_MALLOC_PREFIX;
  
  if(totalSize < size)
    return NULL;

  void *ptr = calloc(1, totalSize);

  if(!ptr)
    return NULL;

  size_t sel_size = *((size_t*)(ptr)) = size;

  if(sel_size == size)
      __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);

  return ((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX;
}