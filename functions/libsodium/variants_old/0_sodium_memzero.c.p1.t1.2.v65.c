The original functionality of `sodium_memzero` function is to secure erase memory contents by zero'ing out. This can be achieved using multiple different approaches based on system/platform. It chose methods in priority as: SecureZeroMemory, memset_s, explicit_bzero, memset_explicit, explicit_memset, memset with a dummy symbol, inline assembly and lastly native setting memory loop.

A program variant or an equivalent version is provided below that retains the same behavior of memory zero setting while changing the code:


sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    RtlSecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U) {
        errno_t result = memset_s(pnt, len, 0, len);
        result != 0 ? sodium_misuse() : (void)(0); /* LCOV_EXCL_LINE */
    }
#elif defined(HAVE_EXPLICIT_BZERO) || defined(HAVE_MEMSET_EXPLICIT) || defined(HAVE_EXPLICIT_MEMSET)
    void * (* volatile const secure_memset)(void *, int, size_t) =
        (volatile void * (*)(volatile void *, int, size_t)) &memset;
    secure_memset(pnt, 0, len);
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif
#else
    volatile unsigned char * pnt_volatile = (volatile unsigned char *) pnt;
    size_t i;

    for (i = 0; i < len; i++) {
        pnt_volatile[i] = 0;
    }
#endif
}


In this variant:

1. _WIN32's `RtlSecureZeroMemory` - A low-level function to securely zeroes out memory.
2. In case of 'defined(HAVE_MEMSET_S)', ternary operator is used instead.
3. An attempt is made to unconditionally merge 'defined(HAVE_EXPLICIT_BZERO)', 'defined(HAVE_MEMSET_EXPLICIT)' and 'defined(HAVE_EXPLICIT_MEMSET)' checks into a single chunk.
4. Loop until all bits are set to 0, use of linear increment loop on else condition.
