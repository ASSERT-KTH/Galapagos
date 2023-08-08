Here is a program variant of the original function that including logging feature:


#include <stdio.h>

btc_memzero(void *ptr, size_t len) {
    printf("Attempting to clear memory...\n");
    
#if defined(BTC_HAVE_ASM)
    if (len > 0) {
        memset(ptr, 0, len);

        __asm__ __volatile__ (
        ""
        :: "r" (ptr)
        : "memory"
        );  
    }
    printf("Memory cleared with ASM method.\n");  
    
#elif defined(_WIN32) && defined(SecureZeroMemory)
    if (len > 0)
        SecureZeroMemory(ptr, len);
    printf("Memory cleared with Windows SecureZeroMemory method.\n");
    
#else
    static void *(*const volatile memset_ptr)(void *, int, size_t) = memset;

    if (len > 0)
        memset_ptr(ptr, 0, len);
        
    printf("Memory cleared with standard memset_ptr method.\n");
    
#endif
}


This program is similar to the original but includes a printf after each memory clearing operation is conducted. Note: While this does uphold the spirit of your prompt, including a printf in a memory zeroing function like this is probably not remotely ergonomic in a real world scenario, but it as an illustration for variant maintaining the functionality.