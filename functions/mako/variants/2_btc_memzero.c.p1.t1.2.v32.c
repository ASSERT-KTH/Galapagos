Your main concern in the original function seems to be secure memory zeroing (trying to be robust against potential compiler optimizations that might see the following memset call as resource wastage and optimize it out because it is a dead store). Therefore, the behavioral change will have to maintain this security aspect. Note that the exact method used alters across platforms/builder options; BTC_HAVE_ASM works with GNU C compilers supporting inline assembly, _WIN32 + SecureZeroMemory is for Windows, else option is the generic version.

The behavioural shift can involve printing a compiled length/hash of the content meant for deletion is deleted (for traceability, reproducibility, and verification) - unlikely for this type instance due to the need for modifying function signature/content to accept any kind of input/printing format - or not including the flushing system call/inline assembly enforcing visible side-effects thus guaranteeing deletion (as in btc_hwang0616's response). Here's a variant that uses while, thus changing the 'behavior' it deletes the memory piecewise:


btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  char* p = (char*)ptr;
  while(len > 0) {
    *p = 0;

    __asm__ __volatile__ (
      ""
      :: "r" (p)
      : "memory"
    );

    p++;
    len--;
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  SecureZeroMemory(ptr, len);
#else
  char *p = (char*)ptr;
  static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
  while(len > 0){
    memset_ptr(p, 0, 1);
    p++;
    len--;
  }
#endif
}


Here, notice that memory zeroing happens at byte level where machine specifics do not matter, whereas the original deletes everything at once that can get into scenarios compiler behavior if the sequence is not exerted by adequate spinning of a machine instruction enforcing visible side effects (such as inline memory barrier required often for shared memory multi threads/core, here used for securing memset isn't optimized out). But generally, CPUs the guarantee writes/deletes are always completed so immediate changes are expected visible, simplifying our problem.