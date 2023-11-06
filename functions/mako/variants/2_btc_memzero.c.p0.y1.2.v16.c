void btc_memzero(void *ptr, size_t len) {
  char *ptr_char;
  size_t counter;

#ifdef BTC_HAVE_ASM
  if (len > 0) {
    __asm__ __volatile__(
    "cld\n\t"
    "rep\n\t"
    "stosb"
    : "=D" (ptr),
      "=c" (counter)
    : "0" (ptr),
      "1" (len),
      "a" (0)
    : "memory", "cc" );
  }
#elif(defined(_WIN32) || defined(WIN32)) && defined(SecureZeroMemory)
  if (len > 0)
    SecureZeroMemory(ptr, len);
#else
  volatile char *vptr = (volatile char *)ptr;

  if (len > 0) {
    while (len--) {
      *vptr++ = 0;
    }
  }
#endif
}