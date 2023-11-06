Variant 1:

btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len);

    __asm__ __volatile__ ("nop"
      :: "r" (ptr)
      : "memory"
    );
  }
#else
  static void *(*volatile p_memset)(void *, int, size_t) = memset;
  if (len > 0)
    p_memset(ptr, 0, len);
#endif
}


Variant 2:

btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM) && !defined(_WIN32)
  if (len > 0) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (::"r" (ptr):"memory");
  }
#elif defined(_WIN32) && !defined(SecureZeroMemory)
  static void *(*volatile pSecureZeroMemory)(void *, size_t) = SecureZeroMemory;
  if (len > 0)
    pSecureZeroMemory(ptr, len);
#else
 static void *(*const volatil pmemset)(void *, int, size_t) = &memset;
 if (len > 0)
    pmemset(ptr, 0, len);
#endif
}


Variant 3:

btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (""
        :
        : "r" (ptr)
        : "memory"
    );
  }
#elif defined(_WIN32) && !defined(SecureZeroMemory)
  static void *(*const volatil sSecureZeroMemory)(void *, size_t) = SecureZeroMemory;
  if (len > 0) 
    sSecureZeroMemory(ptr, len);
#else
  if (len > 0) {
    static void *(*volatile func_memset)(void *, int, size_t) = memset;
    func_memset(ptr, 0, len);
  }
#endif
}
