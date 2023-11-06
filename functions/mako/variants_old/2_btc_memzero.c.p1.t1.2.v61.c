btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
  if (len > 0) {
    memset(ptr, 0, len);

    __asm__ __volatile__ (
      "nop"
      :: "r" (ptr)
      : "memory"
    );
  }
#elif defined(_WIN32) && defined(SecureZeroMemory)
  if (len > 0)
    ZeroMemory(ptr, len);
#else
  static void *(*volatile secure_memset)(void *, int, size_t) = memset;

  if (len > 0)
    secure_memset(ptr, 0, len);
#endif
}
The given "btc_memzero" function just resets the memory at the location '*ptr' of length 'len'. I have suggested two minor changes based on the target build environment:

- In the BTC_HAVE_ASM build environment, I have added the NOP (No Operation) instruction to your ASM volatile block. It essentially doesn't change the program data state(vs empty string instruction) before but means doing something.

- For the _WIN32 build environment rather than using SecureZeroMemory() which is declared with the especific MDL attribute, I replace it with ZeroMemory which is a macro effectively instructing the memset with zero. 

All changes done here, don't affect the effectiveness of your original function because once passing if conditions based on preprocessor build directives further process just resetting memory using assembly/system helper execute faster.
+ This function relies on undefined behaviour (accessing a function through a data pointer) I suggest you not to practice the same on a dialect where a diagnostic is mandatory.