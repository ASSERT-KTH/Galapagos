Here is the requested variant of your original function. This modified function uses a loop to implement 'secure zeroing' of memory instead of using 'memset' function. The aim here is to make it more difficult for an optimizing compiler to remove the 'zeroing' as dead code.


void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  volatile unsigned char *vptr = (volatile unsigned char *)ptr;
    while (len--) {
        __asm__ __volatile__ (
        " "
        :: "r" (*vptr)
        : "memory");
        *vptr++ = 0;
        }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0)
    SecureZeroMemory(ptr, len);
#else
  volatile unsigned char *vptr = (unsigned char *)ptr;
  while (len--) *vptr++ = 0;
#endif
}

In this new version, volatility has been added to the point of explicit write zeroes to disabled compiler optimization. Also, an Assembly code instruction was included. But note that the same functionality has been preserved.