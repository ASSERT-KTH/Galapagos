btc_memzero(void *ptr, size_t len) {
#ifdef BTC_HAVE_ASM
  if (len) {
    memset(ptr, 0, len);
    __asm__ __volatile__ (""
                          : 
                          : "r" (ptr)
                          : "memory");
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  SecureZeroMemory(ptr, len ? len : 0);
#else
  volatile void *(*memset_zfill)(void *, int, size_t) = memset;
  memset_zfill(ptr, 0, len ? len : 0);
#endif
}