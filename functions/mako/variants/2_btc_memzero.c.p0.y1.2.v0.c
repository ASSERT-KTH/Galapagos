void btc_memzero(void *ptr, size_t len) {
#ifdef BTC_HAVE_ASM
  if (len > 0) {
    char* p = (char*)ptr;
    while(len--) {
      __asm__ __volatile__ (
        "xor %[p],%[p]"
        : [p]"=r" (*p)
        :
        : "memory"
      );
      ++p;
    }
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0) 
    SecureZeroMemory(ptr, len);
#else
  void *(*volatile memset_p)(void *, int, size_t) = memset;
  if (len > 0) 
    memset_p(ptr, 0, len);
#endif
}