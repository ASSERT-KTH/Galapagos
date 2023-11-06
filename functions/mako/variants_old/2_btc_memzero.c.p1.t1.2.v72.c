The following function variant has identical functionality as the original function but changes its behaviour by using loops and operators to set memory to 0 instead of calling library functions. This may be less efficient but provides the same result.


#include <stdint.h>

void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    volatile uint8_t *volatile p = (volatile uint8_t *volatile)ptr;
    while (len--) {
      *p++ = 0;
    }

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0) {
    volatile uint8_t *volatile p = (volatile uint8_t *volatile)ptr;
    while (len--) {
      *p++ = 0;
    }
  }
#else
  if (len > 0) {
    volatile uint8_t *volatile p = (volatile uint8_t *volatile)ptr;
    while (len--) {
      *p++ = 0;
    }
  }
#endif
}


In this code, each byte of memory is explicitly zeroed out using a while loop running once for every byte, and pointer arithmetic for memory access. Rather than calling `memset()`, each byte pointed to by `ptr` is specifically set to 0 with `*p++ = 0;`.

The `volatile` keyword is used to prevent compiler optimization, ensuring that the actual zeroing operation isn't ignored by the compiler, even although we know it cannot detect whether it would have any effect. This is essentially the definition of "side effect" that it uses. It works by inhibiting compiler information about the data `p` that may analyze.
Use of `volatile` tells the compiler not to make assumptions about the referenced data and helps in concurrency controls, dealing with hardware mapping, signal handler, etc.
Remember this will not have the exact performance because looping through bytes will be slower than optimized library functions.