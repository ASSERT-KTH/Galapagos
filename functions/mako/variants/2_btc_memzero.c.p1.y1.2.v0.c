btc_memzero_1(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    __asm__ __volatile__ (
      "cld; rep stosb"
      :: "D" (ptr), "a" (0), "c" (len)
      : "memory", "cc"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0)
    SecureZeroMemory(ptr, len);
#else
  static void *(*const volatile memset_ptr_1)(void *, int, size_t) = memset;
  if (len > 0)
    memset_ptr_1(ptr, 0, len);
#endif
}


btc_memzero_2(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len) {
    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0)
    SecureZeroMemory(ptr, len);
#else
  static void *(*volatile memset_fnct)(void *, int, size_t) = memset;
  if (len) 
    memset_fnct(ptr, 0, len);
#endif
}


btc_memzero_3(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len) {
    memset(ptr, 0, len);
    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  SecureZeroMemory(ptr, len);
#else
  static void *(*const volatile memset_ptr_2)(void *, int, size_t) = memset;
  memset_ptr_2(ptr, 0, len);
#endif
}
