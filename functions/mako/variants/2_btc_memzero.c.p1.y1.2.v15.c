Variant 1:

void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len != 0) {
    memset(ptr, 0, len);
    /* Assembler code to enforce memory safety */;
    __asm__ __volatile__ (
    ""
    :: "r" (ptr)
    : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len != 0)
    SecureZeroMemory(ptr, len);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len != 0)
    memset_ptr(ptr, 0, len);
#endif
}


Variant 2:

void btc_memzero(void *ptr, size_t len) {
  if (len <= 0) return;
  
#if defined(BTC_HAVE_ASM)
  memset(ptr, 0, len);

  __asm__ __volatile__ (
    ""
    :: "r" (ptr)
    : "memory"
  );
  
#elif defined(_WIN32) && defined(SecureZeroMemory)
  SecureZeroMemory(ptr, len);

#else
    static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
    memset_ptr(ptr, 0, len);
#endif
}


Variant 3:

void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#else
#if defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0)
    SecureZeroMemory(ptr, len);
#else
  static void *((* const volatile memset_ptr))(void *, int, size_t) = memset;

  if (len > 0)
    memset_ptr(ptr, 0, len);
#endif
#endif
}
