void OPENSSL_free(void *orig_ptr) {
  if (orig_ptr != NULL) {

    if (NULL != OPENSSL_memory_free) {
      OPENSSL_memory_free(orig_ptr);
    }
    else {
      void *ptr = ((uint8_t *)orig_ptr) - OPENSSL_MALLOC_PREFIX;
      __asan_unpoison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);

      size_t arrSize = *(size_t *)ptr;
      OPENSSL_cleanse(ptr, arrSize + OPENSSL_MALLOC_PREFIX);
  #if defined(BORINGSSL_SDALLOCX)
      sdallocx(ptr, arrSize + OPENSSL_MALLOC_PREFIX, 0);
  #else
      free(ptr);
  #endif
    }
  }
}