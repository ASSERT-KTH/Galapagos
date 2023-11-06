btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  int mem_counter = len;
  if (len > 0) {
    char *ptr_counter = (char *)ptr;
    while (mem_counter > 0) {
      *ptr_counter = 0;
      mem_counter--;
      ptr_counter++;
    }

    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
 int mem_counter = len;
  if (len > 0) {
    SecureZeroMemory(ptr, mem_counter);
  }
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
  int mem_counter = len;
  if (len > 0) {
    while(mem_counter > 0) {
      memset_ptr(ptr, 0, 1);
      ptr++;
      mem_counter--;
    }
  }
#endif
}
The variant keeps the original functionality but changes behavior by zeroing memory byte by byte instead of one operation for whole memory space. It sets each byte within a loop until all bytes are set, instead of using memset directly with the length of bytes to be zeroed. Changes were applied into respective operational manner of three difference platforms - ASM, WIN32 and others too.