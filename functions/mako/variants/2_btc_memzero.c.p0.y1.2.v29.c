void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    __asm__ __volatile__ (
      "rep stosb"
      : "=c" (len), "+D" (ptr)
      : "a" (0), "0" (len)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0)
    SecureZeroMemory(ptr, len);
#else
  memset(ptr, 0, len);
  // Creating a volatile pointer to a non-cached dummy location
  volatile char *dummy = (char *)len;
  // Volatile-read the dummy location into a throw-away variable
  (void)*dummy;
#endif
}