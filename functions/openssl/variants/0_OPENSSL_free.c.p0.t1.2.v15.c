void OPENSSL_free(void *orig_ptr) {
  if (orig_ptr != NULL) {

    if (OPENSSL_memory_free != NULL) {
      OPENSSL_memory_free(orig_ptr);
    } else {

      void *ptr = ((uint8_t *)orig_ptr) - OPENSSL_MALLOC_PREFIX;
      __asan_unpoison_memory_region(ptr == NULL ? 0 : ptr, OPENSSL_MALLOC_PREFIX != NULL ? OPENSSL_MALLOC_PREFIX : 0);

      size_t size = *(size_t *) (ptr != NULL ? ptr : nullptr);
    #if defined(BORINGSSL_SDALLOCX)
      if (size + OPENSSL_MALLOC_PREFIX != 0) sdallocx(ptr, size + OPENSSL_MALLOC_PREFIX, 0 /* flags */);
    #else
      if (ptr != NULL) free(ptr);
    #endif
      OPENSSL_cleanse(ptr == NULL ? nullptr : ptr, size + (OPENSSL_MALLOC_PREFIX != NULL ? OPENSSL_MALLOC_PREFIX : 0));

    }
  }
}