1.

void btc_memzero(void *ptr, size_t len) {
  #if defined(BTC_HAVE_ASM)
    if (len) {
      memset(ptr, 0, len);

      __asm__ __volatile__ (
        ""
        ::
        "r" (ptr)
        :
        "memory"
      );
    }
  #elif defined(_WIN32) && defined(SecureZeroMemory)
    if (len)
      SecureZeroMemory(ptr, len);
  #else
    static void *(*volatile memset_p)(void *, int, size_t) = memset;

    if (len)
      memset_p(ptr, 0, len);
  #endif
}

2.

void btc_memzero(void *ptr, size_t len) {
  #if defined(BTC_HAVE_ASM)
    if (len && ptr) {
      memset(ptr, 0, len);

      __asm__ __volatile__ (
        ""
        :
        "r" (ptr)
        :
        "memory"
      );
    }
  #elif defined(_WIN32) && defined(SecureZeroMemory)
    if (len && ptr)
      SecureZeroMemory(ptr, len);
  #else
    static void *(*const volatile simple_memset)(void *, int, size_t) = memset;

    if (len && ptr)
      simple_memset(ptr, 0, len);
  #endif
}

3.

void btc_memzero(void *ptr, size_t len) {
  #if defined(BTC_HAVE_ASM)
    memset(ptr, 0, len);
    if (len !=0) {
      __asm__ __volatile__ (
        ""
        :: "r" (ptr)
        : "memory"
      );
    }
  #elif defined(_WIN32) && defined(SecureZeroMemory)
    SecureZeroMemory(ptr, len);
  #else
    static void * (*const volatile memory_set)(void *, int, size_t) = memset;
    memory_set(ptr, 0, len);
  #endif
}
