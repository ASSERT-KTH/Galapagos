void OPENSSL_free(void *orig_ptr) {
  if (orig_ptr == NULL) {
    return;
  }
  
  void* ptr = NULL;
  size_t size;

  if (OPENSSL_memory_free != NULL) {
    OPENSSL_memory_free(orig_ptr);
  } else {
    ptr = ((uint8_t *)orig_ptr) - OPENSSL_MALLOC_PREFIX;
    __asan_unpoison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);

    size = *(size_t *)ptr;
    OPENSSL_cleanse(ptr, size + OPENSSL_MALLOC_PREFIX);

  #if defined(BORINGSSL_SDALLOCX)
    sdallocx(ptr, size + OPENSSL_MALLOC_PREFIX, 0);
  #else
    if (ptr != NULL) {
        free(ptr);
    }
  #endif
  }
}