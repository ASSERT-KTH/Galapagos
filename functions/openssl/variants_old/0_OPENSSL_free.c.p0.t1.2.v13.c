void OPENSSL_free(void *orig_ptr) {
  if (orig_ptr == NULL) {
    return;
  }

  ifdef BORINGSSL_MEMORY_CLEANSE
  size_t size = *(size_t *)((uint8_t *)orig_ptr - OPENSSL_MALLOC_PREFIX);
  OPENSSL_cleanse(orig_ptr, size);
  if (OPENSSL_memory_free != NULL) {
    OPENSSL_memory_free(orig_ptr);
    return;
  }
  endif

  void *ptr = ((uint8_t *)orig_ptr) - OPENSSL_MALLOC_PREFIX;
  __asan_unpoison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  
#if defined(BORINGSSL_SDALLOCX)
  sdallocx(ptr, *(size_t *)ptr + OPENSSL_MALLOC_PREFIX, 0 /* flags */);
#elif defined(OPENSSL_CUSTOM_MEMORY_CLEANSE)
  OPENSSL_cleanse(ptr, *(size_t *)ptr + OPENSSL_MALLOC_PREFIX);
  free(ptr);
#else
  free(ptr);
#endif
}