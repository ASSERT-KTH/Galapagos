sodium_memzero(void * const pnt, const size_t len)
{
    unsigned char *ptr = (unsigned char*)pnt;
    size_t i;

#if defined(_WIN32) && !defined(__CRT_INLINE)
    for(i = 0; i < len; i++)
    {
        *(ptr + i) = 0;
    }
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U && memset_s(pnt, (rsize_t) len, 0, (rsize_t) len) != 0) {
        sodium_misuse(); /* LCOV_EXCL_LINE */
    }
#else
    memset(ptr, 0, len);

# if HAVE_WEAK_SYMBOLS
    if (len > 0U) {
        _sodium_dummy_symbol_to_prevent_memzero_lto(pnt, len);
    }

# ifdef HAVE_INLINE_ASM
    __asm__ __volatile__ ("" : : "r"(pnt) : "memory");
# endif

# endif
    for (i = 0; i < len; i++) {
        *(ptr + i) = 0;
    }
#endif
}