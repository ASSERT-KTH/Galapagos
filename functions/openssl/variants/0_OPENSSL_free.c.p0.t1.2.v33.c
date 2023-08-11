void OPENSSL_free(void *orig_ptr) {
  if (!orig_ptr) {
    return;
  }

  if (OPENSSL_memory_free) {
    OPENSSL_memory_free(orig_ptr);
    return;
  }

  void *ptr = (uint8_t *)orig_ptr - OPENSSL_MALLOC_PREFIX;

  __asan_unpoison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);
  size_t sz = *((size_t *)ptr);
#ifdef BORINGSSL_SDALLOCX
  OPENSSL_cleanse(ptr, sz + OPENSSL_MALLOC_PREFIX);
  sdallocx(ptr, sz + OPENSSL_MALLOC_PREFIX, 0); 
#else
  OPENSSL_cleanse(ptr, sz);
  free(ptr);
#endif
}