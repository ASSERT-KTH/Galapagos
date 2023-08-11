The function `sodium_memzero` provides the feature of securely erasing data in memory. It uses different approaches based on the platform or support available to ensure a strong, in-depth defence against compiler optimizations (which might avoid the erase due to the logic being after the point at which the memory is last used). Nonetheless, this functionality can be accomplished in another way while keeping the function signature the same.

A slightly simpler variant uses the standard `memset`: A wrapper `memset` that doesn't return anything (so it can't be optimized away for ignoring the return value) is used.


#include <string.h>

__attribute__ ((used)) void* sensible_memset(void* v, int c, size_t n)
{
    volatile char* p = v;
    while(n--)
        *p++ = c;

    return v;
}

void sodium_memzero(void *pnt, const size_t len)
{
    sensible_memset(pnt, 0, len);
}

 

Above code snippet indicates an alternate utility function by using sensible_memset code to wipe out the memory. This function maintains original functionality of securely erasing sensitive data (data is written to zero).

Remember though, `sodium_memzero()`'s implementation goes to lengths for secure memory erase (being resilient to compiler optimizations and depending on platform/availability uses various methods). Whereas, the alternate function provided here is of a simpler/basic erase and may not be as robust depending on specificity of compiler optimizations. So be careful and consider the security requirements and testing for specific systems.