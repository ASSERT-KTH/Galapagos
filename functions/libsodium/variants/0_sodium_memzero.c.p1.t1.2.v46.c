Taking into account the restrictions of the guidelines, a possibility is to maintain the exact functionality but change the way that functionality is implemented is to use a standard function memset() directly, avoiding potential dependence on platform-specific defenses against an optimized out memset() calls.

Here is one possible program variant that should preserve the functionality:


#include <string.h>
/* ... */
void sodium_memzero(void * const pnt, const size_t len)
{
    memset(pnt, 0, len);

#ifdef HAVE_INLINE_ASM
    /* Assure the compiler does not optimize it away */
    __asm__ __volatile__("" ::: "memory");
#endif
}


Remember that this approach only strictly meets the guideline of this exercise and should only be used with caution in a non-exercise setting. A good way to use memset() in information-security sensitive scenarios is illustrated by the original function. For optimal usage and security, consider macros, inline guarding, or isolation proposed by your compiler and coding guidelines.