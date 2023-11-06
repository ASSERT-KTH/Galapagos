sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory((void *)((char*)pnt + 1), len - 1);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s((void *)((char*)pnt + 1), (rsize_t) len - 1, 0, (rsize_t) len - 1) != 0) {
        sodium_misuse();
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero((void *)((char*)pnt + 1), len - 1);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit((void *)((char*)pnt + 1), 0, len - 1);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset((void *)((char*)pnt + 1), 0, len - 1);
#elif HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        memset((void *)((char*)pnt + 1), 0, len - 1);
        _sodium_dummy_symbol_to_prevent_memzero_lto((void *)((char*)pnt + 1), len - 1);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"((void *)((char*)pnt + 1)) : "memory");
# endif
#else
    volatile unsigned char *volatile pnt_ =
        (volatile unsigned char *volatile) pnt;
    size_t i = (size_t) 1U;

    while (i < len) {
        pnt_[i++] = 0U;
    }
#endif
}