void sodium_memzero(void *pnt, size_t len) 
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    int memset_fail = (len > 0 && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len));
    if (memset_fail) 
    {
        sodium_misuse(); 
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pnt, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pnt, 0, len);
#elif HAVE_WEAK_SYMBOLS
    if (len > 0) 
    {
        memset(pnt, 0, len);
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }
# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif
#else
    volatile unsigned char *pnt_ = (unsigned char *) pnt;
    size_t i;

    for (i = 0; i < len; i++, pnt_++) 
    {
        *pnt_ = 0;
    }
#endif
}