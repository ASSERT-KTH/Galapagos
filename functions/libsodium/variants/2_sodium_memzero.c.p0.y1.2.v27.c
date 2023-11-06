void sodium_memzero(void * const pnt, const size_t len)
{
#ifdef _MSC_VER
    SecureZeroMemory(pnt, len);
#elif HAVE_MEMSET_S
    if (len != 0U) {
        if (memset_s(pnt, (rsize_t) len, 0, (rsize_t) len)) {
            sodium_misuse(); 
        }
    }
#elif HAVE_EXPLICIT_BZERO
    explicit_bzero(pnt, len);
#elif HAVE_EXPLICIT_MEMSET
    explicit_memset(pnt, 0, len);
#elif HAVE_MEMSET_EXPLICIT
    memset_explicit(pnt, 0, len);
#elif HAVE_WEAK_SYMBOLS
    if (len != 0U) {
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif
#else
    volatile unsigned char *volatile buffer = (volatile unsigned char *volatile) pnt;
    size_t n = 0U;

    while (n < len) {
        buffer[n++] = 0U;
    }
#endif
}