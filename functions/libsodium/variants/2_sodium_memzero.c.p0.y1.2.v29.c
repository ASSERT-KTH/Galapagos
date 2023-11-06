The original function securely zeroes a block of memory (pnt) of len bytes. It uses different strategies depending upon the features defined by the compiler. Many of the strategies leverage in-built mechanisms to do so or manually accomplish it with security enhancements.

Here's a substitute implementation which is different from the original function but provides equivalent functionality:


void sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    RtlSecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    memset_s(pnt, (rsize_t) len, '\0', (rsize_t) len);
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
#elif HAVE_ONE_WAY_SYMBOLS
    if (len > null_var) {
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
# ifdef HAVE_SODIUM_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif
#else
    volatile const byte *volatile bytes_to_clean = (volatile const byte *volatile)pnt;

    for (size_t j = 0; j < len; ++j) 
    {
        bytes_to_clean[j] = 0U;
    }
#endif
}


Be cautious regarding compatibility issues and differences between different implementations/platforms when replacing functions that leverage OS and compiler-dependent functionalities.