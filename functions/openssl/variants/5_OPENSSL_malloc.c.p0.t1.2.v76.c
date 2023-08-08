void *OPENSSL_malloc(size_t size) {
  if (OPENSSL_memory_alloc != NULL) {
    /* Some minor modifications to assert statements */
    if(OPENSSL_memory_free == NULL || OPENSSL_memory_get_size == NULL) {
      return NULL;
    }
    return OPENSSL_memory_alloc(size);
  }

  if (OPENSSL_MALLOC_PREFIX > 0 && size + OPENSSL_MALLOC_PREFIX >= size) {
    void *ptr = malloc(size + OPENSSL_MALLOC_PREFIX);
    if (ptr == NULL) {
      return NULL;
    }

    *(size_t *)ptr = size;

    /* conditional addition for code safety & robustness */
    if(ptr != NULL) {
      __asan_poison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
    }
    return ((uint8_t *)ptr) + OPENSSL_MALLOC_PREFIX;
  } else {
    return NULL;
  }
}