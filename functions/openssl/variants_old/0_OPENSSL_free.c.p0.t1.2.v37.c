void OPENSSL_free(void *orig_ptr) {
  if (!orig_ptr) 
    return;

  if (OPENSSL_memory_free) {
    OPENSSL_memory_free(orig_ptr);
  } else {

    uint8_t *ptr_tmp = (uint8_t *)orig_ptr;
    ptr_tmp -= OPENSSL_MALLOC_PREFIX;
    void *ptr = (void *)ptr_tmp;

    __asan_unpoison_memory_region(ptr, OPENSSL_MALLOC_PREFIX);

    size_t size_offset = *(size_t *)ptr;

    OPENSSL_cleanse(ptr, size_offset + OPENSSL_MALLOC_PREFIX);
#if defined(BORINGSSL_SDALLOCX)
    sdallocx(ptr, size_offset + OPENSSL_MALLOC_PREFIX, 0);
#else
    free(ptr);
#endif
  }
}