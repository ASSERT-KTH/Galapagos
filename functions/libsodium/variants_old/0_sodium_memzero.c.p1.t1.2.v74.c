
sodium_memzero(void * const pnt, const size_t len)
{
    volatile unsigned char *volatile pnt_ = (volatile unsigned char *volatile) pnt;
    size_t i = (size_t) 0U;

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
#elif defined(HAVE_INLINE_ASM)
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
#else
    for (i = 0; i < len; i++) {
        pnt_[i] = 0U;
    }
#endif
}

In this variant, the criteria used to select the memory zeroing function do not change. If the selected function fails or is not applicable, then a straight forward 'for-loop' based memory setting is used as a fallback.

A reverse order for the selective criteria doesn't really change the functionality as long it remains consistent. For instance, the original `sodium_memzero` function's implementation tests if explicitly secure memory setting operations are available. If they are, the more resilient operations would become a higher priority option than using the 'for-loop' to manually zero out the memory.
However, if the options aren't mutually exclusive, that could affect the functions used to zero out memory. This could have impacts on issues such as security or optimization.

Note: 'Explicit' functions are often preferred due to security considerations as standard functions like 'memset' could be removed during the optimization process if a compiler detects they're 'not required', even though they may be needed for safety purposes in certain situations. As such, repositioning these doesn't change functionality, though for a production environment the original order prioritizing explicit functions would be recommended.