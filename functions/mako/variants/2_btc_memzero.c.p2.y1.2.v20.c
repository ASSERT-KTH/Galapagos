void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len);
    __asm__ __volatile__("mfence" : : : "memory");
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  memset_s(ptr, len, 0, len);
#else
  if(len){
    volatile char *p = ptr;
    while(len--) *p++ = 0;
  }
#endif
}