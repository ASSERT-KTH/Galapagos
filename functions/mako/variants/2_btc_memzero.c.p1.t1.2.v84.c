Here's a modified version:


btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  // Introduce a loop that systematically applies memset for 1 byte at a time,
  // instead of a single bulk application
  if (len > 0) {
    for(size_t i = 0; i < len; ++i)
      memset((char*)ptr + i, 0, 1);
    __asm__ __volatile__(
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  // Introduce a loop that applies SecureZeroMemory function for 1 byte at a time
  if (len > 0) {
    for(size_t i = 0; i < len; ++i)
      SecureZeroMemory((char*)ptr + i, 1);
  }
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
  // Use memset for systematically clearing memory for 1 byte at a time
  if (len > 0) {
    for(size_t i = 0; i < len; ++i)
      memset_ptr((char*)ptr + i, 0, 1);
  }
#endif
}


Just changed how the code handles blocks of memory to zero it out - for different OS/platform conditions, byte-wise operations are preferred over bulk operations which is still synchronised with original functionality. Remember, that the explained code might degrade execution speed.