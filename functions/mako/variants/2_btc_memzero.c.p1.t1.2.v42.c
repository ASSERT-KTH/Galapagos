Here's a variant of the original code that retains its functionality but alters the behavior slightly. This version uses a iterating through individual bytes approach instead of utilizing standardized memory setting functions.


#include <stdlib.h>

void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    char* cptr = ptr;
    for (size_t i = 0; i < len; ++i){
      cptr[i] = 0;
    }
    __asm__ __volatile__ ("":: "r" (ptr): "memory");
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0) {
    char* cptr = ptr;
    for (size_t i = 0; i < len; ++i){
      cptr[i] = 0;
    }
}
#else
  if (len > 0) {
    char* cptr = ptr;
    for (size_t i = 0; i < len; ++i){
      cptr[i] = 0;
    }
  }
#endif
}

This version fills the memory block byte by byte, which may be useful if for any reason you wanted to do more complex operations or checks on individual bytes before overwriting them. However, do be aware that this will likely be slower than the standardized memory methods originally used due to them typically having specific optimizations to write large amounts of memory quickly.