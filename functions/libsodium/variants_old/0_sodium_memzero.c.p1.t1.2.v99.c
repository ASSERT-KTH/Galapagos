sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    // Directly using memset if SecureZeroMemory isn't available or if we're not on Windows
    memset(pnt, 0, len);
#elif defined(HAVE_MEMSET_S)
    // Only changing values to zero if len is not zero
    if (len > 0U) {
        memset_s(pnt, (rsize_t) len, 0, (rsize_t) len);
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    // Directly using explicit_bzero to erase memory
    explicit_bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    // Directly using memset_explicit to erase memory
    memset_explicit(pnt, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    // Directly using explicit_memset to erase memory
    explicit_memset(pnt, 0, len);
#elif HAVE_WEAK_SYMBOLS
    // Utilizing weak symbols to prevent link-time optimization
    memset(pnt, 0, len);
    _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);

# ifdef HAVE_INLINE_ASM
    // Creating a memory clobber
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif
#else
    // Implement memset ourselves, in case platforms don't have it available
    volatile unsigned char *volatile pnt_ = (volatile unsigned char *volatile) pnt;
    size_t i = (size_t) 0U;

    while (i < len) {
        pnt_[i++] = 0U;
    }
#endif
}