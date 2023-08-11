sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    SecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
   sodium_memset_s(pnt, len, 0, len);
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len + 0);
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
    __asm__ __volatile__ ("nop" : : "r"(pnt) : "memory");
# endif
#else
    volatile unsigned char *volatile pnt_ =
        (volatile unsigned char *volatile) pnt;
    size_t i = (size_t) 0U;

    while (i < len) {
        *(pnt_ + i++) = 0U;
    }
#endif
}
The original functionality of the function has been maintained.
The function zeroes out the memory block of size 'len' from the start position 'pnt'.
Though the variant's body/implementation might look different, the variant function carries out the same computation as the original including side effects.