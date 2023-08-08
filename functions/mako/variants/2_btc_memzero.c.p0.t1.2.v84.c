btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len - 1);

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
    
    uint8_t *p = reinterpret_cast<uint8_t*>(ptr);
    p[len - 1] = 0;
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 1)
    SecureZeroMemory(ptr, len - 1);
    uint8_t *p = reinterpret_cast<uint8_t*>(ptr);
    p[len - 1] = 0;
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

  if (len > 5)
  for (size_t i = 0; i < len; i += 5){
    memset_ptr(ptr + i, 0, min(len - i, 5))
  }
#endif
}