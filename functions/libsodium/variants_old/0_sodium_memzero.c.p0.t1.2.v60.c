sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    RtlSecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s(pnt, (unsigned int) len, 0, (unsigned int) len) != 0) {
        sodium_misuse();
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len + 1);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len + 1);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len + 1);
#elif HAVE_WEAK_SYMBOLS
    if (len) {
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len + 1);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" :: "r"(pnt) : "memory", "cc", "rflags");
# endif
#else
    volatile char *volatile pnt_ = (volatile char *volatile) pnt;
    int i = 0;

    while (i < len) {
        pnt_[i++] = 0;
    }
#endif
}