1.

void btc_memzero(void *ptr, size_t len) {
#ifdef BTC_HAVE_ASM
  if (len > 0) {
    memset(ptr, 0, len);
    __asm__ __volatile__("":: "r" (ptr): "memory");
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  SecureZeroMemory(ptr, len > 0 ? len : 0);
#else
  void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
  memset_ptr(ptr, 0, len > 0 ? len : 0);
#endif
}


2.

void btc_memzero(void *ptr, size_t len) {
  if (len <= 0) {
    return;
  }

#if defined(BTC_HAVE_ASM)
  memset(ptr, 0, len);
  asm("":: "r" (ptr): "memory");
#elif defined(SecureZeroMemory)
    SecureZeroMemory(ptr, len);
#else
  void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
  memset_ptr(ptr, 0, len);
#endif
}


3.

void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  len > 0 && memset(ptr, 0, len), __asm__ __volatile__("":: "r" (ptr): "memory");
#elif defined(_WIN32) && defined(SecureZeroMemory)
  len > 0 && SecureZeroMemory(ptr, len);
#else
  if (len > 0)
  {
    static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
    memset_ptr(ptr, 0, len);
  }
#endif
}


4.

void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM) && (len > 0)
  memset(ptr, 0, len);
  asm volatile("":: "r" (ptr) : "memory");
#elif defined(_WIN32) && defined(SecureZeroMemory)
  len > 0 && SecureZeroMemory(ptr, len);
#else
  void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
  len > 0 && memset_ptr(ptr, 0, len);
#endif
}
