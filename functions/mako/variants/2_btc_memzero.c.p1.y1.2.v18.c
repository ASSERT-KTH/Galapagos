Variant 1: Adding a condition to verify that the pointer being passed is not null.


void btc_memzero(void *ptr, size_t len) {
  if (ptr == NULL) return;
  
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len);

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
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len > 0)
    memset_ptr(ptr, 0, len);
#endif
}


Variant 2: Short circuit the function if length is zero.


void btc_memzero(void *ptr, size_t len) {
  if (len == 0) return;
  
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


Variant 3: Consolidating the len > 0 checks to the start of the function for non-bitcoin/asm variants


void btc_memzero(void *ptr, size_t len) {
  if(len <= 0)
    return;

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

Rare case variants

Variant 4: Replace the use of SecureZeroMemory function with RtlSecureZeroMemory


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
#elif defined(_WIN32) && !defined(SecureZeroMemory)
  if (len > 0)
    RtlSecureZeroMemory(ptr, len);
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len > 0)
    memset_ptr(ptr, 0, len);
#endif
}
