sodium_memzero(void * const pnt, const size_t len)
{
    volatile unsigned char *pntv = (volatile unsigned char*) pnt;
    size_t i;
  
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    memset_s(pntv, (rsize_t) len, 0, (rsize_t) len);
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pntv, len);
#elif defined(HAVE_MEMSET_EXPLICIT)
    memset_explicit(pntv, 0, len);
#elif defined(HAVE_EXPLICIT_MEMSET)
    explicit_memset(pntv, 0, len);
#elif HAVE_WEAK_SYMBOLS
    memset(pntv, 0, len);
    _sodium_dummy_symbol_to_prevent_memzero_lto(pntv, len);
    __asm__ __volatile__ ("" : : "r"(pntv) : "memory");
#else
    for (i = 0; i < len; i++, pntv++)
    {
        *pntv = 0;
    }
#endif
}