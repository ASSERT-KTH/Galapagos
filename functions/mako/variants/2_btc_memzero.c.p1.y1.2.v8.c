Variant 1:

void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      ""
      :: "m" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0)
    SecureZeroMemory(ptr, len);
#else
  static void *(*volatile memset_func)(void *, int, size_t) = memset;

  if (len > 0)
    memset_func(ptr, 0, len);
#endif
}


Variant 2:

void btc_memzero(void *ptr, size_t len) {
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
  if (len)
    SecureZeroMemory(ptr, len);
#else
  static void *(*const volatile memset_func)(void *, int, size_t) = memset;

  if (len)
    memset_func(ptr, 0, len);
#endif
}


Variant 3:

void btc_memzero(void *ptr, size_t len) {
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
  if (len)
     memset(ptr, 0, len);
#else
  static void *(*const volatile secure_memset)(void *, int, size_t) = memset;

  if (len)
    secure_memset(ptr, 0, len);
#endif
}
