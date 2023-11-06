The following program variant maintains the original functionality of the function while changing its behavior:


#include <string.h>

void sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    // Check the length to zero.
    if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse();
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    // Clear the memory more explicitly.
    memset_explicit(pnt, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
# ifdef HAVE_INLINE_ASM
    // In case of inline assembly, introduce an assembly no-op before the memzero.
    __asm__ __volatile__ ("NOP\n\t" : : "r"(pnt) : "memory");
# endif
#else
    volatile unsigned char *volatile pnt_ =
        (volatile unsigned char *volatile) pnt;
    size_t i = (size_t) 0U;

    // Reverse set memory to zero.
    while (i < len) {
        pnt_[len - i - 1] = 0U;
        ++i;
    }
#endif
}


Changes:
- For the fallback implementation, memory is set to zero in the reverse order compared to the original code.
- Additionally, before the normalization, the null operation (NOP) is introduced to potentially prevent certain compiler or CPU optimizations from occurring (although modern CPUs and compilers are likely to ignore it).

Note however, the above changes, do not add any additional benefit from secure programming perspective. It is to mostly provide an example for demonstration purpose without, in any way, indicating real use. Use the secure functions as provided in the original code. It is possible the reverse ordering and addition of NOP at assembly won't provide real benefit/alteration in majority of the modern compilers+ses and can be ignored. It is used to convey the idea keeping the original function's ability identical while altering the underlying code's behavior.