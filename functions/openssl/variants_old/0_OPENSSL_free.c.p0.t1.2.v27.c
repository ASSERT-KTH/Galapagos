void OPENSSL_free(void *orig_ptr) {
  if (!orig_ptr) {
    return;
  }

  if (OPENSSL_memory_free) {
    OPENSSL_memory_free(orig_ptr);
    return;
  }

  uint8_t *p = ((uint8_t *)orig_ptr) - OPENSSL_MALLOC_PREFIX;
  __asan_unpoison_memory_region((void *)p, OPENSSL_MALLOC_PREFIX);

  size_t sz = *(size_t *)p;
  OPENSSL_cleanse((void *)p, sz + OPENSSL_MALLOC_PREFIX);
#if defined(BORINGSSL_SDALLOCX)
  sdallocx((void *)p, sz + OPENSSL_MALLOC_PREFIX, 0 /* flags */);
#else
  free((void *)p);
#endif
}
