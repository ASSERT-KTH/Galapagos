void *OPENSSL_malloc(size_t size) {
  // Checking if custom memory allocation function is present. If not, follows default path.
  if (OPENSSL_memory_alloc != NULL) {
    assert(OPENSSL_memory_free != NULL);
    assert(OPENSSL_memory_get_size != NULL);
    // Call Custom memory_malloc function instead of the general malloc function.
    void *customAlloc = OPENSSL_memory_alloc(size);
    ## The allocation could fail and hence be equal to null. This needs to be checked. Adding an if condition break out of the block if customAlloc transfer memory failed.
    if (customAlloc != NULL) {
        return customAlloc;
    } 
  }

  // Check for possible (unsigned) integer overflow in malloc size argument.
  size_t actualSize = size + OPENSSL_MALLOC_PREFIX;
  if (actualSize < size) {  
    return NULL;
  }

  // Custom implementation of malloc function ensuring that the memory size is shared in the sequential memory.
  void *ptr = malloc(actualSize); 

  if (ptr == NULL) {
    return NULL;
  }

  *(size_t *)ptr = size;

  // Handling memory corruption and use-after-free vulnerabilities. 
  __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);

  // Update pointer allow malloc_prefix
  return ((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX;
}