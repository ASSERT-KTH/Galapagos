void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len != 0) {
    memset(ptr, 0, len);
    
    __asm__ __volatile__("nop"
                         ::"r"(ptr)
                         : "memory");
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len != 0)
    SecureZeroMemory(ptr, len);
#else
  volatile void *(*memset_ptr_volatile)(void *, int, size_t) = memset;

  if (len != 0)
    memset_ptr_volatile(ptr, 0, len);
#endif
}