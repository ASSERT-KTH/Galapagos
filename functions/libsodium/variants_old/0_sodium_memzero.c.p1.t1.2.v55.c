
sodium_memzero(void * const pnt, const size_t len)
{
#if defined(_WIN32) && !defined(__CRT_INLINE)
    RtlSecureZeroMemory(pnt, len);
#elif defined(HAVE_MEMSET_S)
    if (len > 0U) {
        char *pos = pnt;
        size_t remainder = len;
        
        while (remainder > 0) {
            const size_t block = (remainder < RSIZE_MAX) ? remainder : RSIZE_MAX;
            if (memset_s(pos, (rsize_t) block, 0, (rsize_t) block) != 0) {
                sodium_misuse(); /* LCOV_EXCL_LINE */
            }
            remainder = len - block;
            pos += block;
        }
    }
#elif defined(HAVE_EXPLICIT_BZERO)
    explicit_bzero(pnt, len);
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
    size_t i = (size_t) 0U;

    while (i < len) {
        pnt_[i++] = 0U;
    }
#endif
}

Changes in the variant:
1. For Windows systems, if the C Runtime Library inline method is not defined, call RtlSecureZeroMemory instead of SecureZeroMemory.
2. If memset_s is available, use blocks if the length is large. Large blocks can cause errors because memset_s is defined to operate on values of rsize_t which could possibly smaller than size_t. Split it into blocks if such case occurs, assuming the relevant C libraries are properly defended against optimization attacks to prevent an intermittent mode where data is only part-overwritten.