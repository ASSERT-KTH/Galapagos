void OPENSSL_free(void *orig_ptr) {
  if (orig_ptr == NULL) {
    return;
  }

  size_t size = 0;
  void *ptr;
 
  // Reverse the order of checks.
  // Instead of checking free first, unpoison the memory region first.
  if (OPENSSL_memory_free == NULL) {
    ptr = ((uint8_t *)orig_ptr) - OPENSSL_MALLOC_PREFIX;
    __asan_unpoison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
    size = *(size_t *)ptr;
    OPENSSL_cleanse(ptr, size + OPENSSL_MALLOC_PREFIX);
  } else {
    OPENSSL_memory_free(orig_ptr);
    return;
  }
  
#if defined(BORINGSSL_SDALLOCX)
  sdallocx(ptr, size + OPENSSL_MALLOC_PREFIX, 0 /* flags */);
#else
  free(ptr);
#endif
}