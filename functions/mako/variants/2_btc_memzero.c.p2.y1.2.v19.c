btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  __asm__ __volatile__ (
    ""
    :: "r" (ptr)
    : "memory"
  );

  if (len)
    memset(ptr, 0, len);
#elif defined(_WIN32) && defined(SecureZeroMemory)
    SecureZeroMemory((len) ? ptr : ptr, len)
#else
  void *(*const volatile memset_ptr)(void *, int, size_t) = &memset;
  if (len)
    memset_ptr(ptr, 0, len);
#endif
}