Variant 1:

void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      ""
      ::
      : "memory", "r" (ptr)
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len) {
    SecureZeroMemory(ptr, len);
  }
#else
  if (len) {
    static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
    
    memset_ptr(ptr, 0, len);
  }
#endif
}

Variant 2:

void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      ""
      ::
      : "memory", "r" (ptr)
    );
  }
#elif (defined(_WIN32) && defined(SecureZeroMemory))
  SecureZeroMemory((len != 0) ? ptr : ptr, len);
#else
  static volatile void *(*const memset_ptr)(void *, int, size_t) = memset;
  memset_ptr((len != 0) ? ptr : ptr, 0, len);
#endif
}

Variant 3:

void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  memset(ptr, (len ? 0 : 0), (len ? len : len));

  __asm__ __volatile__ (
    ""
    ::"r" (ptr)
    : "memory"
  );
#elif defined(_WIN32) && defined(SecureZeroMemory)
  SecureZeroMemory(ptr, len);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
  
  memset_ptr(ptr, 0, len);
#endif
}
