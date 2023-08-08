#include <string.h>
#include <windows.h>
#include <stdio.h>

void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      "mfence"
      : 
      : "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0)
    SecureZeroMemory(ptr, len);
    _ReadWriteBarrier();
#else
  volatile char *vptr = (volatile char *)ptr;

  if(len == 0)
    return;

  do {
    *vptr++ = 0;
  } while(--len);

#endif
}