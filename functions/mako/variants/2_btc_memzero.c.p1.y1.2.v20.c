Variant 1:

void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len != 0) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      ""
      :  // Empty output list.
      : "r" (ptr)  // Input list includes pointer.
      : "memory"  // Clobbers memory.
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len != 0) {
    SecureZeroMemory(ptr, len);
  }
#else
  static void *(*const volatile memset_fn)(void *, int, size_t) = memset;

  if (len != 0) {
    memset_fn(ptr, 0, len);
  }
#endif
}


Variant 2:

void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      "" :: "r" (ptr) : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len) {
    SecureZeroMemory(ptr, len);
  }
#else
  static void *(*const volatile memzero)(void *, int, size_t) = memset;

  if (len)
    memzero(ptr, 0, len);
#endif
}

Variant 3:

void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len);

    __asm__ __volatile__ ("" :: "r" (ptr) : "memory");
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0) {
    SecureZeroMemory(ptr, len);
  }
#else
  static void *(*const volatile clear_ptr)(void *, int, size_t) = memset;

  if (len > 0)
    clear_ptr(ptr, 0, len);
#endif
}
