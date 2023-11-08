void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len) {
    __asm__ __volatile__ (
      "cld\n\t"
      "rep\n\t"
      "stosb"
      : "=c" (len), "=Di" (ptr)
      : "a" (0), "1" (ptr), "0" (len)
      : "flags", "memory"
     );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len) 
    SecureZeroMemory(ptr, len);
#else
  static void *(*const volatile memset_ftn)(void *, int, size_t) = memset;

  if (len) 
    memset_ftn(ptr, 0, len);
#endif
}