The following C code change is a modification to alter the behavior of the original function by adding a debug print statement to display the size of data that is being wiped every invocation. While the original function does its job silently, this modified version will print the wipe operation information. Additionally, an #ifdef DEBUG preprocessor statement is introduced to allow optional generation of debugging information.


#include<stdio.h>

#if defined(DEBUG)
#define DEBUG_PRINT_LEN(t) printf("Wiping %zu bytes of data\n", t)
#else
#define DEBUG_PRINT_LEN(t) 
#endif

void sodium_memzero(void * const pnt, const size_t len)
{
    DEBUG_PRINT_LEN(len);

#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse();
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
    #ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
    #endif
#else
    volatile unsigned char *volatile pnt_ =
        (volatile unsigned char *volatile) pnt;
    size_t i = (size_t) 0U;

    while (i < len) {
        pnt_[i++] = 0U;
    }
#endif
}


Please note DEBUG_PRINT_LEN(t) acts as a function-esque macro, where it conditionally expands to executable code based on the compilation flags. If DEBUG is defined at compile time, DEBUG_PRINT_LEN(t) replaced with printf(“Wiping %zu bytes of data\n”, t). If DEBUG isn't defined, it gets replaced with an empty string effectively getting ignored by the compiler.
