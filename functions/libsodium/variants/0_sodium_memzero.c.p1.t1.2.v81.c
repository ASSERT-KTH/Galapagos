Here, the aim is to change the behaviour without hindering the original functionality which is to securely nullify the array in memory and prevent it from being unused/optimized away resulting in the secure clearing of the memory.

The changes include a change in strategy between `_WIN32`,  `HAVE_MEMSET_S`, `HAVE_EXPLICIT_BZERO`, `HAVE_MEMSET_EXPLICIT`,`HAVE_EXPLICIT_MEMSET`, `HAVE_WEAK_SYMBOLS`  which use built APIs and custom clearing in an 'else' block.

sodium_memzero(void * const pnt, const size_t len)
{
#if defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
#elif defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
    # ifdef HAVE_INLINE_ASM
      __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
    # endif
#else
    volatile unsigned char *volatile pnt_ =
        (volatile unsigned char *volatile) pnt;
    size_t space_remaining = len;

    while (space_remaining--) {
        pnt_[len - (1 + space_remaining)] = 0U;
    }
#endif
}