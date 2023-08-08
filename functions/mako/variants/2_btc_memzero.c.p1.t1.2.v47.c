Here's a program variant that essentially is calling the zero memory behaviour in a different manner for instances where BTC_HAVE_ASM is undefined.


void btc_memzero(void *ptr, size_t len) {
#if defined(BTC_HAVE_ASM)
    if (len > 0) {
        memset(ptr, 0, len);

        __asm__ __volatile__ (""
                                :: "r" (ptr)
                                : "memory");
    }
#elif defined(_WIN32) && defined(SecureZeroMemory)
    SecureZeroMemory(ptr, len);
#else
    if (len > 0) {
        char *cleanIt;
        cleanIt = (char*) ptr;
        while (len--)
              *cleanIt++ = 0;
    }
#endif
}


This version includes the inline code that performs the zeroing functionality for undescribed operating systems. It works by iterating through the pointer's referencing memory address space and manually setting each space to zero. This is equivalent to calling memset with a zero fill character. Adding this to an "else" statement after checking for pointers to SecureZeroMemory helps ensure correct implementation of the memory cleanup. However, please add caution regarding portability of this approach. Depending on the system, you may need additional code to handle padding. Furthermore, this approach may slightly hurt performance if len is large due to no CPU usage or working set optimization that standard functions like memset would generally have.
