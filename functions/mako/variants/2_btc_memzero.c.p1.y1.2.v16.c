
void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  __asm__ __volatile__ (
      "rep stash"
      :: "c" (len),"a" (0x0), "D" (ptr)
      : "memory", "cc"
  );
#elif defined(_WIN32) && defined(SecureZeroMemory)
    RtlSecureZeroMemory(ptr, len);
#else
  static void *volatile *(*memset_ptr)(void*, int, size_t);
  if(!memset_ptr)
    memset_ptr = memset;
  if(len > 0)
    memset_ptr(ptr, 0, len);
#endif
}



void btc_memzero(void *ptr, size_t len) {
  #if defined(BTC_HAVE_ASM)
    asm ("rep stosb" : : "D" (ptr), "a" (0), "c" (len) : "memory");
  #elif defined(_WIN32) && defined(SecureZeroMemory)
    SecureZeroMemory(ptr, len);
  #else
    volatile char *p = ptr;
    while (len--) *p++ = 0;
  #endif
}



void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  __asm__ __volatile__ (
      "rep ; stosl"
      :: "D" (ptr), "a" (0), "c" (len/4) 
      : "memory", "cc"
  );
  __asm__ __volatile__ (
      "rep ; stosb" 
      :: "D" (ptr+(len/4)*4), "a" (0), "c" (len%4) 
      : "memory", "cc"
  );
#elif defined(_WIN32) && defined(SecureZeroMemory)
    SecureZeroMemory(ptr, len);
#else
  memset(ptr, 0, len);
#endif
}
