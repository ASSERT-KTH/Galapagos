Below is the code with changes.


void btc_memzero(void *ptr, size_t len) {
  #if defined(BTC_HAVE_ASM)
    if (len > 0) {
      memset(ptr, 0, len);
      __asm__ __volatile__(
        "rep stosb" 
        : 
        : "D" (ptr), "a" (0), "c" (len) 
        :
      );
    }
  #elif defined(_WIN32) && defined(SecureZeroMemory)
    EnterCriticalSection();
    if (len > 0) {
      SecureZeroMemory(ptr, len);
    }
    LeaveCriticalSection();
  #else 
    static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;
    if (len > 0) {
      memset_ptr(ptr, 0, len);
      __asm__ __volatile__("" ::: "memory");
    }
  #endif
} 


In the above changed version for the 'BTC_HAVE_ASM' case, you can use the STOSB instruction, which store AL at the address ES:(E)DI and then and increment or decrement DI depending on the value of DF. ES should already be set, so don't worry about that. They both does whatever operation and then increments or decrements a register, so they can be useful in certain situations, particularly ones that involves memory operation.

For '_WIN32' case, EnterCriticalSection() and LeaveCriticalSection() APIs have been used with SecureZeroMemory() to provide thread safety in case of concurrent calls.

For, remaining case outside 'BTC_HAVE_ASM' and '_WIN32', "memory" clobber tell gcc that the assembly code modifies memory in an unpredictable fashion and prevent it from storing values in registers across the asm and so, secure value cannot be obtained through cold boot attack.