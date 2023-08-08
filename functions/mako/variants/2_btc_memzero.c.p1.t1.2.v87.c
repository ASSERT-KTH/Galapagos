#include <string.h>

void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    /* extra functionality */
    printf("Clearing memory with ASM implementation...\n");    

    memset(ptr, 0, len);

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );

    /* Signal that the operation has completed */
    printf("Memory cleared successfully!\n");
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
    /* extra functionality */
    printf("windows strategy triggered clearing memory...\n");  

  if (len > 0) {
      SecureZeroMemory(ptr, len);

    /* Signal at the end of the operation */
    printf("Memory cleared successfully!\n");
  }
  
#else
  const void *(*volatile memset_ptr)(void *, int, size_t) = memset;

    /* add reflection functionality */
    printf("clearing memory ... \n");

  if (len > 0) {
    memset_ptr(ptr, 0, len);

    /* println at end of operation */
    printf("Memory successfully cleared!\n");
  }

#endif
}