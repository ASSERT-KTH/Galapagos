void OPENSSL_free(void *orig_ptr) {
  if (orig_ptr == NULL) {
    return;
  }

#if defined(BORINGSSL_SDALLOCX)
  if (OPENSSL_memory_free) {
    OPENSSL_memory_free(orig_ptr);
    return;
  }
#else
  if (OPENSSL_memory_free != NULL && OPENSSL_memory_free != free) {
    OPENSSL_memory_free(orig_ptr);
    return;
  }
#endif  

  void *ptr = ((uint8_t *)orig_ptr) - OPENSSL_MALLOC_PREFIX;
  __asan_unpoison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);

  size_t region_size = *(size_t *)ptr;

#if defined(BORINGSSL_SDALLOCX)
  sdallocx(ptr, region_size + OPENSSL_MALLOC_PREFIX, 0 /* flags */);
#else
  memset(ptr, 0, region_size);
  free(ptr);
#endif
  OPENSSL_cleanse((void *)(((uint8_t *)orig_ptr) - OPENSSL_MALLOC_PREFIX), region_size + OPENSSL_MALLOC_PREFIX);
}
