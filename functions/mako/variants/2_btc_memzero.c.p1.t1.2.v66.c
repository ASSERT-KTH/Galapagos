#include <string.h>

void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    __asm__ __volatile__ (
      "mov %1, %%ecx\n\t"
      "xor %%al, %%al\n\t"
      "rep stosb\n\t"
      :
      : "D" (ptr), "r" (len)
      : "cc", "memory", "eax", "ecx"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0)
    SecureZeroMemory(ptr, len);
#else
  if (len > 0) {
      volatile char *volatile p = (volatile char *volatile)ptr;
      while (len--) { *p++ = 0; }
  }
#endif
}