void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    bzero(ptr, len);

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len )
    RtlSecureZeroMemory(ptr, len);
#else
  static void *(*const volatile bzero_ptr)(void *, size_t) = bzero;

  if (len )
    bzero_ptr(ptr, len);
#endif
}