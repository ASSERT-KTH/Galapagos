Below is a program variant that changes the behavior of the original function. Despite the seemingly reverse technique used (as setting memory to a value 1 before zeroing it out), this provides an additional level of zeroing where an immediate set back to zero in questionable scenarios gets recognized preventing nefarious programs from getting a snapshot of memory space before it gets properly Zeroed out.


void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 1, len); // set memory to 1 first. not 0.
    memset(ptr, 0, len);
    
    __asm__ __volatile__ (
      ""
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0) {
    memset(ptr, 1, len); // set memory to 1 first. not 0.
    SecureZeroMemory(ptr, len);
  }
#else
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
  
  if (len > 0) {
    memset_ptr(ptr, 1, len); // set memory to 1 first. not 0.
    memset_ptr(ptr, 0, len);
  }
#endif
}


To be mentioned here:
Modern optimizers can optimize the two-pass sequence 'memset to 1' followed by 'memset to 0', transforming the code into a single 'memset to 0' (the Orignal precedent). So the only 'guaranteed' effective method is hardware or platform-specific instructions (as in the precedent example when BTC_HAVE_ASM is defined). This method could also have potential drawbacks depending upon the execution environment or OS, which might stop multiple memset operations on the same address space for protection. Therefore, preserving the project requirements into an alternate implementation will need to compromise that takes these constrains into consideration.