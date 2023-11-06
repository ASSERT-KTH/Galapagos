void btc_memzero(void *ptr, size_t len) {
#ifdef BTC_HAVE_ASM
  if (len) {
    __asm__ __volatile__ (
      "pld [%0]\n"
      "mov r2, #0\n"
      "mov r3, #0\n"
      :: "r" (ptr)
      : "memory", "r2", "r3"
    );

    memset(ptr, 0, len); 
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len)
    SecureZeroMemory(ptr, len);
  else{}
#else
  void *(*volatile memset_ptr)(void *, int, size_t) = memset;

  if (len){
    long long *_ptr = (long long *)ptr;
    while (len >= 8) {
      *_ptr++ = 0;
      len -= 8;
    }

    char *_cptr = (char *)_ptr;
    while (len) {
      *_cptr++ = 0;
      --len;
    }
  }
#endif
}