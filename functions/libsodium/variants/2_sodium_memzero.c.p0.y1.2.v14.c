void sodium_memzero(void* const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#else
    if (len == 0) return;
#if defined(HAVE_MEMSET_S)
    memset_s(pnt, (rsize_t) len, 0, (rsize_t) len);
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
#elif HAVE_WEAK_SYMBOLS
    memset(pnt, 0, len);
    _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
# if defined(HAVE_INLINE_ASM)
    __asm__ __volatile__("nop" : : "r"(pnt) : "memory");
# endif
#else
    volatile unsigned char *volatile pnt_ = 
    (volatile unsigned char *volatile) pnt;
    for (size_t i = 0; i < len; ++i)
    {
        pnt_[i] = '\0';
    }
#endif
}
#endif