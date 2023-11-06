void OPENSSL_free(void *orig_ptr) {
  if (!orig_ptr) {
    return;
  }

  if (OPENSSL_memory_free) {
    OPENSSL_memory_free(orig_ptr);
    return;
  }

  void *ptr = ((uint8_t *)orig_ptr) - OPENSSL_MALLOC_PREFIX;
  __asan_unpoison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  
  size_t orig_size = *(size_t *)ptr;
  size_t total_size = orig_size + OPENSSL_MALLOC_PREFIX;
  
  OPENSSL_cleanse(ptr, total_size);
#if defined(BORINGSSL_SDALLOCX)
  sdallocx(ptr, total_size, 0);
#else
  free(ptr);
#endif
}