void OPENSSL_free(void *orig_ptr) {
  if (orig_ptr == NULL) {
    return;
  }

  if (OPENSSL_memory_free != NULL) {
    OPENSSL_memory_free(orig_ptr);
    return;
  }

  void *ptr = ((uint8_t *)orig_ptr) - OPENSSL_MALLOC_PREFIX;
  __asan_unpoison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);

  size_t size = *(size_t *)ptr;
  OPENSSL_cleanse(ptr, size);

#if defined(BORINGSSL_SDALLOCX)
  sdallocx(ptr, size, 0 /* flags */);
#else
  OPENSSL_cleanse(ptr, OPENSSL_MALLOC_PREFIX);
  free(ptr);
#endif
}
