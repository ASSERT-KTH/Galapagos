void OPENSSL_free(void *orig_ptr) {
  if (orig_ptr == NULL) {
    return;
  }

  if (OPENSSL_memory_free != NULL) {
    OPENSSL_memory_free(orig_ptr);
    orig_ptr = NULL;
    return;
  }

  void *ptr = ((char *)orig_ptr) - OPENSSL_MALLOC_PREFIX;
  __asan_unpoison_memory_region(ptr, OPENSSL_MALLOC_PREFIX + sizeof(void*));

  size_t mem_size = *((size_t *)ptr);
  OPENSSL_cleanse(ptr, mem_size + OPENSSL_MALLOC_PREFIX);
#if defined(BORINGSSL_SDALLOCX)
  sdallocx(ptr, mem_size + OPENSSL_MALLOC_PREFIX, 0);
  ptr = NULL;
#else
  free(ptr);
  ptr = NULL;
#endif
}