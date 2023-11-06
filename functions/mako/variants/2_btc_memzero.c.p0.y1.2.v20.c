void btc_memzero(void *ptr, size_t len) {
#ifdef BTC_HAVE_ASM
  if(len > 0) {
    void * unused = memset(ptr, 0, len);
    asm volatile("" : : "r"(ptr), "r"(unused) : "memory");
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if(len > 0) {
    SecureZeroMemory(ptr, len);
  }
#else
  volatile typeof(memset) *vmemset = memset;
  if(len > 0) {
    vmemset(ptr, 0, len);
  }
#endif
}